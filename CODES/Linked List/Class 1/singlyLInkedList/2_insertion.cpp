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
void PrintLL(Node* head) {
    Node *temp = head;
    while(temp!=NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
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

    // creation of Node

    // node a // static method

    Node *first = new Node(10);
    Node *second= new Node(30);
    Node *third = new Node(40);
    Node *fourth = new Node(60);
    Node *fifth = new Node(70);

    // bad pratice - normal method to create  linked list
    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    

    Node*head = first;
    Node*tail = fifth;

    PrintLL(head);

    insertAtTail(head, tail, 500);
    PrintLL(head);
    
}