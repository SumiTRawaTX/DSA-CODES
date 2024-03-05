#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev; // previous pointer
        Node* next; // next pointer
        // Default Constructor
        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        // Parameterized Constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

// print the  doubly linked list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// get length of doubly linked list
int getLength(Node* &head){
    Node* temp = head;
    int len = 1;
    while(temp->next != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// insert at node
void insertAtHead(Node* &head,Node* &tail,int data){
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Normal steps to be followed
    Node* newNode = new Node(data);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;

}

// insert at tail
void insertAtTail(Node* &head,Node* &tail,int data){
    // Empty linked list
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

// insert at position
void insertAtPosition(int pos,Node* &head,Node* &tail,int data){
    if(pos == 1){
        insertAtHead(head,tail,data);
        return;
    }
    int len = getLength(head);
    if(pos > len){
        insertAtTail(head,tail,data);
        return;
    }
    int i = 1;    
    Node* prevNode = head;
    while(i < pos - 1){
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;
    Node* newNode = new Node(data);
    prevNode -> next = newNode;
    newNode->prev = prevNode;
    curr->prev = newNode;
    newNode->next = curr;

}

void deleteNode(Node* &head, Node* &tail, int position) {
    // empty Linked list
    if(head == NULL) {
        cout << "cannot delete, because LL is empty" << endl;
        return;
    }
    if(head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = getLength(head);
    // deletion from head
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    // deletion from tail
    else if(position == len) {
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }

    // delete from any postion
    else {
        // step1- set prevNode/currNode/nextNode
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1) {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }

        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;

    }
}

int main(){

    Node* head = new Node(10);
    Node* tail = head;

    // insertAtHead(head,tail,20); 
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);

    insertAtPosition(5,head,tail,60);
    print(head);

    cout<<endl;

    cout<<"Length = "<< getLength(head);

    // deleteNode(head, tail, 3);
    // print(head);

    return 0;

}