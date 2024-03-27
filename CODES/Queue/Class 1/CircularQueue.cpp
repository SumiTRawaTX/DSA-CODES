#include<iostream>
using namespace std;

class cirQueue {
    public:
    int size;
    int *arr;
    int front;
    int rear;

    // constructor
    cirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // push function
    void push(int data) {
        // step 1- check queue is full or not
        if(front == 0 && rear == size-1) {
            cout << "Q is full" << endl;
        }
        //step 2- insert first element
        else if(front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }
        //step 3- circular nature
        else if(rear = size-1 && front!=0) {
            rear = 0;
            arr[rear] = data;
        }
        // step4- nornal
        else {
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        // step1- empty check
        if(front == -1) {
            cout << "Q is empty" << endl;
        }
        //step2- single element
        else if(front == rear) {
            arr[front] == -1;
            front = -1;
            rear = -1;
        }
        // step3- circular handle
        else if(front == size-1) {
            front = 0;
        }
        // step4- default case
        else {
            front++;
        }
    }
};

int main() {

}