#include<iostream>
#include<queue>
using namespace std;

int main () {
    queue<int> q;

    //insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // size of queue
    cout << "size of queue is " << q.size() << endl;

    // removal
    q.pop();

    cout << "size of queue is " << q.size() << endl;

    // empty or not
    if(q.empty()) {
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }

    // front element
    cout << "first element is " << q.front() << endl;

}