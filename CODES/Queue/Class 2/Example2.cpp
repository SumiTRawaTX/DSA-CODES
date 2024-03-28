#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseK(queue<int>& q, int k) {
    // step1- queue ->k element ->stack
    stack<int> s;
    int count = 0;
    int n = s.size();
    if(k == 0 || k > n) {
        return;
    }

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count ++;

        if(count == 0) break;
    }

    // step 2- stack -> q me wapis
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // step 3- push n-k element from q front to back
    count = 0;
    while(!q.empty() && n-k != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k) break;
    }
}

int main() {

    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseK(q, 3);

    cout << " reverse q by kth element" << endl;
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;

}