/* 
 * Reverse linked List 
 * 1. simple reverse
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(1)
 * 2. recursive approach
 *    Time Complexity: O(n), Visiting over every node one time 
 *    Auxiliary Space: O(n), Function call stack space
 * 3. Stack based approach (Not implemented) 
 * 4. Reverse a Linked List in group of Given Size.
 *    Time Complexity: O(n), Visiting over every node one time 
 *    Auxiliary Space: O(n/k), Function call stack space during recursion
 *
 */


#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
      data = val;
      next = NULL;
    }
};

class LinkedList {
public:
    Node *head;
    LinkedList() {
      head = NULL;
    }
    void print();
    void push(int val);
    void simpleReverse();
    Node* recursiveReverse(Node *node);
    Node* reverseGroupOfNelements(Node* head, int k);
};

void
LinkedList::print()
{
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void
LinkedList::push(int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void
LinkedList::simpleReverse()
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node*
LinkedList::recursiveReverse(Node *node)
{
    if(node == NULL) {
        return NULL;
    }
    if(node->next == NULL) {
        head = node;
        return node;
    }
    Node *node1 = recursiveReverse(node->next);
    node1->next = node;
    node->next = NULL;
    return node;
}

Node*
LinkedList::reverseGroupOfNelements(Node* head, int k) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 1;
    
    if(head == NULL) {
        return NULL;
    }
    while(curr != NULL && count <= k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if (next != NULL) {
        head->next = reverseGroupOfNelements(next, k);
    }
    return prev;
}

int
main()
{
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
    
    ll.head = ll.reverseGroupOfNelements(ll.head, 2);
    ll.print();
    
}
