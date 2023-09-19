/* 
 * Intersection of two Sorted Linked Lists
 *    Time Complexity: O(m+n), where m and n are number of nodes in first and second linked lists respectively. 
 *                     Only one traversal of the lists are needed.
 *    Auxiliary Space: O(min(m,n)),The output list can store at most min(m,n) nodes.
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
    Node* findIntersection(Node* head1, Node* head2);
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

Node*
LinkedList::findIntersection(Node* head1, Node* head2)
{
    Node* res = NULL;
    Node* temp = NULL;
    Node* prev = NULL;

    while(head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            temp = new Node(head1->data);
            if (res == NULL) {
                res = temp;
            } else {
                prev->next = temp;
            }
            prev = temp;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        }
    }
    return res;
}

int
main() {
    LinkedList ll1;
    ll1.push(6);
    ll1.push(4);
    ll1.push(3);
    ll1.push(2);
    ll1.push(1);
    ll1.print();

    LinkedList ll2;
    ll2.push(8);
    ll2.push(6);
    ll2.push(4);
    ll2.push(2);
    ll2.print();

    LinkedList ll3;
    ll3.head = ll3.findIntersection(ll1.head, ll2.head);

    ll3.print();

    return 0;
}