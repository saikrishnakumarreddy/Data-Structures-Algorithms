/* 
 * Add 1 to number represented in linked list 
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
private:
    void add_one_util();
public:
    Node *head;
    LinkedList() {
        head = NULL;
    }
    void print();
    void push(int val);
    void add_one();
    void reverseLL();
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
LinkedList::reverseLL()
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void
LinkedList::add_one_util() {
    Node* temp = head;
    Node* prev;
    int carry = 1;
    int sum = 0;

    while(temp != NULL) {
        sum = temp->data + carry;
        carry = sum>=10 ? 1 : 0;

        sum = sum%10;

        temp->data = sum;
        prev = temp;
        temp = temp->next;
    }

    if (carry > 0) {
        prev->next = new Node(carry);
    }
}

void
LinkedList::add_one() {
    reverseLL();
    add_one_util();
    reverseLL();
}

int
main() {
    LinkedList ll;
    ll.push(9);
    ll.push(8);
    ll.push(9);
    ll.push(9);
    ll.push(9);

    ll.print();
    ll.add_one();
    ll.print();
}