/* 
 * Add two numbers represented in linked list 
 *    Time Complexity: O(m+n), where m and n are numbers of nodes in first and second lists respectively. The lists need to be traversed only once.
 *    Auxiliary Space: O(m+n),A temporary linked list is needed to store the output number
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
    Node* addTwoLL(Node* first, Node* second);
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

Node*
LinkedList::addTwoLL(Node* first, Node* second) {
    // res is head node of the resultant list
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    // while both lists exist
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
          // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = new Node(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest.
        else
            prev->next = temp;
       
        // Set prev for next insertion
        prev = temp;
 
        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = new Node(carry);
    // return head of the resultant list
    return res;
}

int
main() {
    LinkedList ll1;
    ll1.push(9);
    ll1.push(8);
    ll1.push(9);
    ll1.push(9);
    ll1.push(9);
    ll1.print();

    LinkedList ll2;
    ll2.push(9);
    ll2.push(8);
    ll2.push(9);
    ll2.push(9);
    ll2.push(9);
    ll2.print();

    ll1.reverseLL();
    ll2.reverseLL();

    LinkedList ll3;
    ll3.head = ll3.addTwoLL(ll1.head, ll2.head);

    ll3.reverseLL();
    ll3.print();

    return 0;
}