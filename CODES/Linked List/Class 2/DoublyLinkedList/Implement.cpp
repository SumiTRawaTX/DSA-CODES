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

        node(int n) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};


// print a doubly  linked list
void print(node* head) {
    node* temp = head;
    while(head != NULL) {
        cout << temp->data << endl;
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

int main() {

    node* head = new node(10);

    return 0;
}