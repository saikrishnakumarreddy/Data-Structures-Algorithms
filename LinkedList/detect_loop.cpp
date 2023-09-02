/* 
 * Detect loop in linked List 
 * 1. Hashing approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(n)
 * 2. Two pointer(slow and fast) approach
 *    Time Complexity: O(n), Only one traversal of the loop is needed.
 *    Auxiliary Space: O(1)
 * 3. Mark visted nodes without modifying the Node structure but it will modify the linked list next node pointers
 *    Time complexity: O(N), Only one traversal of the loop is needed.
 *    Auxiliary Space: O(1). 
 * 4. By Sorting length (Not implemented)
 *    Time Complexity: O(n^2), For every node calculate the length of that node from the head by traversing.
 *    Auxiliary Space: O(1)
 *
 */


#include<iostream>
#include<bits/stdc++.h>
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
    bool hashLoopDetect(Node* node);
    bool TwoPointerLoopDetect(Node* node);
    bool MarkVisitLoopDetect(Node* node);
};

void
LinkedList::push(int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

bool
LinkedList::hashLoopDetect(Node* node) {
    unordered_set<Node*> s;
    
    while(node != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you will be encountering the
        // node for the second time).
        if(s.find(node) != s.end()) {
            return true;
        }
        // If we are seeing the node for
        // the first time, insert it in hash       
        s.insert(node);
        node = node->next;
    }
    return false;
}

bool
LinkedList::TwoPointerLoopDetect(Node* node) {
    Node* slowptr = head;
    Node* fastptr = head;
    
    while(slowptr && fastptr && fastptr->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        
        if (slowptr == fastptr) {
            return true;
        }
    }
    return false;
}

bool
LinkedList::MarkVisitLoopDetect(Node* node) {
    Node* temp = new Node;
    Node* next;
    while(node != NULL) {
        // This condition is for the case when there is no loop
        if (node->next == NULL) {
            return false;
        }
        // Check if next is already pointing to temp
        if (node->next == temp) {
            return true;
        }
        // Store the pointer to the next node
        // in order to get to it in the next step
        next = node->next;
        // Make next point to temp
        node->next = temp;
        // Get to the next node in the list
        head = next;
    }
    return false;
}

int
main() {
    LinkedList ll;
    ll.push(1);
    ll.push(7);
    ll.push(4);
    ll.push(9);


    ll.head->next->next->next = ll.head;

    if(ll.hashLoopDetect(ll.head)) {
        cout<< "Loop found" <<"\n";
    } else {
        cout<< "No Loop" <<"\n";
    }
    
    if(ll.TwoPointerLoopDetect(ll.head)) {
        cout<< "Loop found" <<"\n";
    } else {
        cout<< "No Loop" <<"\n";
    }
    
    if(ll.MarkVisitLoopDetect(ll.head)) {
        cout<< "Loop found" <<"\n";
    } else {
        cout<< "No Loop" <<"\n";
    }
}
