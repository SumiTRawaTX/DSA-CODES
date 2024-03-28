#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q) {
    stack<int> s;

    // Transfer elements from queue to stack
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // Transfer elements from stack back to queue
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
}


int main() {
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverse(q);

    cout << "printing Queue" << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}