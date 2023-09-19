/* 
 * Find first Node of loop in linked List 
 * 1. Hashing approach
 *    Time Complexity: O(n), Traversing over the linked list of size N. 
 *    Auxiliary Space: O(n), due to hashing 
 * 2. Two pointer(slow and fast) approach
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
private:
    void find_first_node_in_loop(Node* slowptr, Node* head);
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void push(int data);
    bool find_loop_using_two_ptr(Node* head);
    Node* find_loop_using_hash(Node* head);
};

void
LinkedList::push(int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node*
LinkedList::find_loop_using_hash(Node* head) {
    unordered_set<Node*> uset;
    while (head != NULL) {
        if(uset.find(head) != uset.end()) {
            return head;
        } else {
            uset.insert(head);
        }
        head = head->next;
    }
    return NULL;  
}

void
LinkedList::find_first_node_in_loop(Node* slowptr, Node* head) {
    Node* ptr1 = slowptr;
    Node* ptr2 = slowptr;

    unsigned int k=1;
    while ( ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    ptr1 = head;
    ptr2 = head;

    for(int i=0; i<k; i++) {
        ptr1 = ptr1->next;
    }

    while(ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    cout<<"First Node in loop: "<<ptr1->data<<"\n";
}

bool
LinkedList::find_loop_using_two_ptr(Node* head) {
    Node* slowptr = head;
    Node* fastptr = head;

    while(slowptr && fastptr && fastptr->next) {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;

        if (slowptr == fastptr) {
            find_first_node_in_loop(slowptr, head);
            return true;
        }
    }
    return false;
}

int main() {
    LinkedList ll;
    ll.push(1);
    ll.push(7);
    ll.push(4);
    ll.push(9);

    ll.head->next->next->next->next = ll.head->next;
    
    if(ll.find_loop_using_two_ptr(ll.head)) {
        cout<< "Loop found" <<"\n";
    } else {
        cout<< "No Loop" <<"\n";
    }

    Node* temp = ll.find_loop_using_hash(ll.head);
    if (temp != NULL) {
        cout<<"First Node in loop: "<<temp->data<<"\n";
    }
}