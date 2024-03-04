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

// find length of a matrix
int getLength(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count ++;
        temp = temp->next;
    }
    return count;
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

//insert at any position
void insertAtPosition(Node* head, Node* &tail, int data, int position) {
    // if(position<=1) {
    //     cout << "please enter valid position" << endl;
    //     return;
    // }

    int length = getLength(head);

    if(position <= 1) {
        insertAtHead(head, tail, data);
    }

    else if(position > length+1) {
        insertAtTail(head, tail, data);
    }
    
    else {
        // insert at middle


        //step1- create a new node
        Node* newNode = new Node(data);
        // step2- traverse prev/curr to position
        Node*prev = NULL;
        Node* curr = head;
        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // step 3 - attach the node
        prev->next = newNode;
        newNode->next = curr;

        if(curr = NULL) {
            tail = newNode;
        }
    }
}

int main() {

    Node* head = NULL;
    Node*tail = NULL;

    insertAtTail(head, tail, 300);
    insertAtTail(head, tail, 400);
    insertAtTail(head, tail, 500);
    insertAtTail(head, tail, 600);

    printLL(head);

    // insertAtPosition(head, tail, 10, 0);
    // insertAtPosition(head, tail, 10, 100);

    insertAtPosition(head, tail, 1000, 11);
    insertAtPosition(head, tail, 654, 0);
    printLL(head);
    
}
