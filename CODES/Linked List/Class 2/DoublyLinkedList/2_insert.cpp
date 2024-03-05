#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* prev;
        node* next;

        node() {
            this->prev = NULL;
            this->next = NULL;
        }

        node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};


// print a doubly  linked list
void print(node* head) {
    node* temp = head;
    while(head != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
}


// find the length of doubly linked list
int getLength(node* head) {
    node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count ++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(node* &head, node* &tail, int data) {
    // LL is empty
    if(head == NULL) {
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }

    // LL is not empty
    else {
        node* newNode = new node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(node* &head, node* &tail, int data) {
    // if LL is empty
    if(head == NULL) {
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }

    // LL is not empty
    else {
        node* newNode = new node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int main() {

    node *head = NULL;
    node *tail = NULL;

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    print(head);

    cout << endl;

    insertAtTail(head, tail, 90);
    print(head);

    return 0;
}