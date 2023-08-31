/* reverse linked List 
 * 1. simple reverse
 *    Time Complexity: O(N), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(1)
 * 2. recursive approach
 *    Time Complexity: O(N), Visiting over every node one time 
 *    Auxiliary Space: O(N), Function call stack space
 * 3. stack based approach (Not implemented) 
 */


#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    
    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    
    void simpleReverse() {
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
    Node* recursiveReverse(Node *node) {
        if (node == NULL) {
            return NULL;
        }
        if (node->next == NULL) {
            head = node;
            return node;
        }
        Node* node1  = recursiveReverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
        
    }
};

int main() {
    LinkedList ll;
    ll.push(1);
    ll.push(7);
    ll.push(4);
    ll.push(9);
    ll.push(3);
    ll.push(6);
    
    ll.print();
    ll.recursiveReverse(ll.head);
    ll.print();
    
    ll.simpleReverse();
    ll.print();
    
}
