/* 
 * heightWithRecursion
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(N), due to recursive stack
 * heightWithoutRecursion
 *  Time Complexity: O(N)
 *  Auxiliary Space: O(N), due to queue space
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

int heightWithoutRecursion(Node* root) {
    queue<Node*> q;
    int height = 0;

    if (root == NULL) {
        return 0;
    }
    q.push(root);

    while(q.empty() == false) {

        int count = q.size();

        for (int i=0; i<count; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        height++;
    }
    return height;
}

int heightWithRecursion(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(heightWithRecursion(node->left), heightWithRecursion(node->right));
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int height = heightWithRecursion(root);
    cout << "Height of binary tree is "<< height <<"\n";

    height = heightWithoutRecursion(root);
    cout << "Height of binary tree is "<< height <<"\n";
    return 0;
}
