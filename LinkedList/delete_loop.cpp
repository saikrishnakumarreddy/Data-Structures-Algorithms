/* 
 * Detect loop in linked List 
 * 1. Hashing approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(n), due to hashing 
 * 2. Two pointer(slow and fast) approach
 *    Time Complexity: O(n), Only one traversal of the loop is needed.
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
    void removeLoop(Node* fastptr, Node* head);
public:
    Node *head;
    LinkedList() {
        head = NULL;
    }
    void print();
    void push(int val);
    bool TwoPointerLoopDetect(Node* node);
    bool hashAndRemove(Node* head);
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

bool
LinkedList::TwoPointerLoopDetect(Node* node) {
    Node* slowptr = head;
    Node* fastptr = head;
    
    while(slowptr && fastptr && fastptr->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        
        if (slowptr == fastptr) {
            removeLoop(fastptr, node);
            return true;
        }
    }
    return false;
}

void
LinkedList::removeLoop(Node* loopNode, Node* head) {
    Node* ptr1 = loopNode;
    Node* ptr2 = loopNode;

    unsigned int k = 1;

    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    ptr1 = head;

    ptr2 = head;
    for(int i=0; i<k; i++) {
        ptr2 = ptr2->next;
    }

    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr2->next != ptr1) {
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
}

bool
LinkedList::hashAndRemove(Node* head) {
    unordered_map<Node*, int> node_map;
    Node* last = NULL;

    while(head != NULL) {
        if(node_map.find(head) == node_map.end()) {
            node_map[head]++;
            last = head;
            head = head->next;
        } else {
            last->next = NULL;
            return true;
        }
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


    ll.head->next->next->next->next = ll.head;
    
    if(ll.TwoPointerLoopDetect(ll.head)) {
        cout<< "Loop found, Removing loop" <<"\n";
        ll.print();

    } else {
        cout<< "No Loop" <<"\n";
    }

    ll.head->next->next->next->next = ll.head;
    
    if(ll.hashAndRemove(ll.head)) {
        cout<< "Loop found, Removing loop" <<"\n";
        ll.print();

    } else {
        cout<< "No Loop" <<"\n";
    }
}