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

        ~Node() {
            cout << " Destructor called for: " << this->data << endl;
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

void deleteNode(Node* head, Node* tail, int position ) {
    // empity list
    if(head == NULL) {
        cout << "cannot delete anything" << endl;
        return ;
    }

    if(head == tail) {
        // single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = getLength(head);

    // delete from head
    if(position == 1) {
        // first node delete
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    // delete from tail
    else if(position == len) {
        // last node delete
        Node* prev = head;
        while(prev-> next  != tail) {
            prev = prev->next;
        }

        // prev node - null 
        prev->next = NULL;

        // node delete
        delete tail;

        // update tail
        tail = prev;
    }

    // delete from any where
    else {
        // at any position

        // step1 - traverse
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }

        //step 2 - next me curr ka next node add kro
        prev->next = curr->next;
        //step3 - curr ko null
        curr->next = NULL;
        //step4 - delete
        delete curr;
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

    InsertAtHead(head, tail, 453);
    PrintLL(head);

    deleteNode(head, tail, 7);
    PrintLL(head);
    cout << endl;

    deleteNode(head, tail, 3);
    PrintLL(head);
    cout << endl;

    return 0;

}