#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            // cout << "I am inside default constructor" << endl;
            this->next = NULL;
        }

        Node(int data) {
            // cout << "I am inside param constructor" << endl;
            this->data = data;
            this->next = NULL;
        }
};

// printing full linked list 
void printLL(Node* head) {
    Node *temp = head;
    while(temp!=NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}


// insert at head
void  insertAtHead(Node* &head, Node* &tail, int data) {
    // NULL Case Handle
    if(head == NULL) {
        // empty LL
        // step 1- create a new node
        Node * newNode = new Node(data);
        //step2- update head
        head = newNode;
        tail = newNode;
    }

    else {
        // non-empty wala case
        // create a new node
        Node* newNode = new Node(data);
        // attach new node to head node
        newNode->next = head;
        //update head
        head = newNode;
    }
}

// insert at Tail
void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        //empty LL
        // step 1 - create a node
        Node* newNode = new Node(data);
        // step2- single node so head and tail are at same point
        head = newNode;
        tail = newNode;
    }
    else {
        //non-empty case
        // create a new node
        Node* newNode = new Node(data);
        // tail node connect with new node
        tail->next = newNode;
        // update tail
        tail = newNode;
    }
}

int main() {

    Node* head = NULL;
    Node*tail = NULL;

    insertAtHead(head, tail, 100);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 300);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 500);
    insertAtTail(head, tail, 600);

    printLL(head);

    
}