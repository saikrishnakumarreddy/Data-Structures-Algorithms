 
/* 
 * maxWidth
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

int maxWidth(Node* root) {
    int res=0;
    if (root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);

    while(q.empty() == false) {

        int count = q.size();
        res = max(res,count);

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
    }
    return res;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    int width = maxWidth(root);
    cout << "Max width of bt is "<<width<<"\n";
 
    return 0;
}
