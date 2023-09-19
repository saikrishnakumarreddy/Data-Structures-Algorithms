/* 
 * Remove duplicates in a sorted linked List 
 * 1. Hashing approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(n), due to hashing 
 * 2. Iterative approach
 *    Time Complexity: O(n), Only one traversal of the loop is needed.
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
    void remove_dup_in_sorted_ll();
    void remove_dup_in_sorted_ll_using_hash();
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
LinkedList::remove_dup_in_sorted_ll() {
    Node* curr = head;
    Node* next_next;

    if (head == NULL || head->next == NULL) {
        return; // No duplicates to remove
    }

    while(curr && curr->next) {
        if (curr->data == curr->next->data) {
            next_next = curr->next->next;
            delete curr->next; // Free the memory for the duplicate node
            curr->next = next_next;
        } else {
            curr = curr->next;
        }
    }
}

void
LinkedList::remove_dup_in_sorted_ll_using_hash() {
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
    ll.push(5);
    ll.push(4);
    ll.push(3);
    ll.push(2);
    ll.push(2);
    ll.push(2);
    ll.push(1);
    ll.push(1);

    ll.print();
    ll.remove_dup_in_sorted_ll_using_hash();
    ll.print();

    ll.push(1);
    ll.print();
    ll.remove_dup_in_sorted_ll();

    ll.print();
}