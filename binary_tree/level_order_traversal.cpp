 
/* 
 * printLevelOrder
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(N)
 * printLevelOrderLineByLine
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

void printLevelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(q.empty() == false) {
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

void printLevelOrderLineByLine(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(q.empty() == false) {

        int count = q.size();

        for (int i=0; i<count; i++) {
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
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    cout << "Level Order traversal of binary tree Line by Line \n";
    printLevelOrderLineByLine(root);
 
    return 0;
}
