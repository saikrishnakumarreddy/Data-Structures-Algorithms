 
/* 
 * printReverseLevelOrder
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(N)
 */

#include<iostream>
#include<queue>
#include<stack>
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

void printReverseLevelOrder(Node* root) {
    Node* curr;
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while(q.empty() == false) {
        curr = q.front();

        q.pop();
        s.push(curr);

        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    while(s.empty() == false) {
        curr = s.top();
        cout<<curr->key <<" ";
        s.pop();
    }
    cout<<"\n";
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Reverse Level Order traversal of binary tree is \n";
    printReverseLevelOrder(root);
 
    return 0;
}
