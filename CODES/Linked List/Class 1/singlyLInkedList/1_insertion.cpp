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


// insert at head
void  InsertAtHead(Node* &head, Node* &tail, int data) {
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
    Node*tail = first;

    PrintLL(head);

    InsertAtHead(head, tail, 500);
    PrintLL(head);
}