/* 
 * Move last element to the front in the linked list 
 * 1. Simple iterative approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(1)
 */

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        next = NULL;
    }
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
    void mv_last_ele_to_front_in_ll();
};

void
LinkedList::push(int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

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
LinkedList::mv_last_ele_to_front_in_ll() {
    Node* temp = head;
    Node* prev = head;

    while(temp != NULL && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
}

int
main() {
    LinkedList ll;
    ll.push(5);
    ll.push(4);
    ll.push(3);
    ll.push(2);
    ll.push(1);

    ll.print();
    ll.mv_last_ele_to_front_in_ll();
    ll.print();
}