/* 
 * printLevelOrderMethod1
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(N)
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

void printLevelOrderMethod1(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while( q.empty() == false) {
        Node* curr = q.front();

        cout<<curr->key<< " ";
        q.pop();

        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout<<"\n";
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
