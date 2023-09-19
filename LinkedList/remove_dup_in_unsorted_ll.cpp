/* 
 * Remove duplicates from an unsorted linked List 
 * 1. Hashing approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(n), due to hashing 
 * 2. Iterative approach
 *    Time Complexity: O(n^2)
 *    Auxiliary Space: O(1)
 */

#include<iostream>
#include<unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
    Node(int n) {
        data = n;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void print();
    void push(int n);
    void remove_dup_in_unsorted_ll();
    void remove_dup_in_unsorted_ll_using_hash();
};

void
LinkedList::push(int n) {
    Node* temp = new Node(n);
    temp->next = head;
    head = temp;
}

void
LinkedList::print() {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void
LinkedList::remove_dup_in_unsorted_ll() {
    Node *ptr1, *ptr2, *dup, *prev;

    ptr1 = head;

    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1->next;
        prev = ptr1;

        while(ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                dup = ptr2;
                prev->next = ptr2->next;
                ptr2 = prev->next;
                delete dup;
            } else {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void
LinkedList::remove_dup_in_unsorted_ll_using_hash() {
    unordered_set<int> uset;
    Node* temp = head;
    Node* prev = head;

    while(temp != NULL) {
        if(uset.find(temp->data) != uset.end()) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            uset.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
}

int
main() {
    LinkedList ll;
    ll.push(6);
    ll.push(5);
    ll.push(6);
    ll.push(4);
    ll.push(3);
    ll.push(2);
    ll.push(3);
    ll.push(2);
    ll.push(3);
    ll.push(1);

    ll.print();
    ll.remove_dup_in_unsorted_ll();

    ll.print();
}