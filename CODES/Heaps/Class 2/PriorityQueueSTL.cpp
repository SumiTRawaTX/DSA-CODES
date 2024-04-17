#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq; // created max heap
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "top element is " << pq.top() << endl;

    pq.pop();

    cout << "top element is " << pq.top() << endl;

    pq.pop();
    cout  << "top element is " << pq.top() << endl;

    cout << "size of priority queue is " << pq.size() << endl;

    if(pq.empty()) {
        cout << "Max heap is empty" << endl;
    }
    else {
        cout << "Max heap is not empty" << endl; 
    }


}