#include<iostream>
using namespace std;

class Deque {
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

        // push function
    void pushRear(int data) {
        // step 1- check queue is full or not
        if(front == 0 && rear == size-1) {
            cout << "Q is full" << endl;
            return;
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

    void pushFront(int data) {
        // step 1- check queue is full or not
        if(front == 0 && rear == size-1) {
            cout << "Q is full" << endl;
            return;
        }
        //step 2- insert first element
        else if(front == -1) {
            front = rear = 0;
            arr[front] = data;
        }
        //step 3- circular nature
        else if(front == 0 && rear != size-1) {
            front = size-1;
            arr[front] = data;
        }
        // step4- nornal
        else {
            front--;
            arr[front] = data;
        }
    }

    void popfront() {
        // step1- empty check
        if(front == -1) {
            cout << "Q is empty" << endl;
            return;
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

    void popRear() {
        // step1- empty check
        if(front == -1) {
            cout << "Q is empty" << endl;
            return;
        }
        //step2- single element
        else if(front == rear) {
            arr[front] == -1;
            front = -1;
            rear = -1;
        }
        // step3- circular handle
        else if(rear == 0) {
            rear = size - 1;
        }
        // step4- default case
        else {
            rear--;
        }
    }
};

int main() {
    
    return 0;
}