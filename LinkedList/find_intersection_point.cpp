/* 
 * Intersection point of two Linked Lists
 *    Time Complexity: O(m+n)
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
    int intersectPoint(Node* head1, Node* head2);
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

int
LinkedList::intersectPoint(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    int len1=0;
    int len2=0;
    int i=0;
    int min=0;
    while(temp1 != NULL) {
        temp1 = temp1->next;
        len1++;
    }
    while(temp2 != NULL) {
        temp2 = temp2->next;
        len2++;
    }
    temp1 = head1;
    temp2 = head2;
    min = (len1>len2) ? len1-len2 : len2-len1;

    for(i=0; i<min; i++) {
        if (len1>len2) {
            temp1 = temp1->next;
        } else if (len1<len2) {
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int
main() {
    /*
        Create two linked lists
     
        1st 3->6->9->15->30
        2nd 10->15->30
     
        15 is the intersection point
    */
    LinkedList ll1; // main code needs to be corrected here
    ll1.push(30);
    ll1.push(15);
    ll1.push(9);
    ll1.push(6);
    ll1.push(3);
    ll1.print();

    LinkedList ll2;
    ll2.push(30);
    ll2.push(15);
    ll2.push(10);
    ll2.print();

    LinkedList ll3;
    int point = ll3.intersectPoint(ll1.head, ll2.head);

    cout<<"Intersection point: "<<point<<"\n";

    return 0;
}