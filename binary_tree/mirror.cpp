/* 
 * Mirror
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(h), where h is the height of the tree. due to recursion call stack.
 */

#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void mirror(Node** root) {
    if (*root == NULL) {
        return;
    }
    swap((*root)->left,(*root)->right);
    if ((*root)->left != NULL) {
        mirror(&((*root)->left));
    }
    if ((*root)->right != NULL) {
        mirror(&((*root)->right));
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    cout<<"Inorder of bt is ";
    inorder(root);
    cout<<"\n";
    cout<<"Inorder of Mirror bt is ";
    mirror(&root);
    inorder(root);
    cout<<"\n";
    return 0;
}
