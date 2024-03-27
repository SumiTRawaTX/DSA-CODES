#include<iostream>
using namespace std;

class Queue {
    public:

    int *arr;
    int size;
    int front;
    int rear;

    //constructor
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    
    // push function
    void push(int data) {
        if(rear == size) {
            cout << "Queue is Full!" << endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    // pop function
    void pop() {
        if(front == rear) {
            cout << "Q is empty " << endl;
        } 
        else {
            arr[front] = -1;
            front++;
            if(front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    // getFront function
    int getFront() {
        if(front == rear) {
            cout << "Q is empty" << endl;
            return -1;
        }
        else {
            return arr[front];
        }
    }

    // function isEmpty
    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    // get size function
    int getSize() {
        return rear - front;
    }

};

int main() {

    Queue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(25);

    cout << "size of queue is " << q.getSize() << endl;

    q.pop();

    cout << "size of queue is " << q.getSize() << endl;

    if(q.isEmpty()) {
        cout << "Q is empty " << endl;
    }
    else {
        cout << "Q is not empty" << endl;
    }
}