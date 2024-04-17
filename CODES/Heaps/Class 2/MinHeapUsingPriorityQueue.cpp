#include<iostream>
#include<queue>
using namespace std;

int main() {

    // min Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "top element is " << pq.top() << endl;
    pq.pop();

    cout << "size " << pq.size() << endl;
    cout << "top element is " << pq.top() << endl;

    pq.pop();
    cout << "top element is " << pq.top() << endl;

    if(pq.empty()) {
        cout << "Min heap is empty" << endl;
    }
    else {
        cout << "Min heap is not empty" << endl;
    }

}