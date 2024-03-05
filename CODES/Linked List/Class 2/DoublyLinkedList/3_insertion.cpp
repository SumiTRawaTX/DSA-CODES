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

void insertAtTail(node* &head, node* &tail, int data){
    // Empty linked list
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    node* newNode = new node(data);
    tail->next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void inserAtPosition(node* &head, node* &tail, int data, int position) {

  int len = getLength(head);
  
  // LL is empty
  if(head == NULL) {
    node* newNode = new node(data);
    head = newNode;
    tail = newNode;
  }

  else {
    // not empty
    if(position == 1) {
      insertAtHead(head, tail, data);
    }
    else if(position == len+1) {
      insertAtTail(head, tail, data);
    }
    else {
      // insert in middle
      node* newNode = new node(data);
      // step2- set prev and curr pointer
      node* prevNode = NULL;
      node* currNode = NULL;
      while(position != 1) {
        position--;
        prevNode = currNode;
        currNode = currNode->next;
      }

      // step3 - pointer update
      prevNode->next = newNode;
      newNode->prev = prevNode;
      newNode->next = currNode;
      currNode->prev = newNode;
    }
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

    // insertAtTail(head, tail, 900);
    // print(head);
   
   inserAtPosition(head, tail, 1000, 1);
   print(head);
    return 0;
}