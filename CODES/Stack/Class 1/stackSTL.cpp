#include<iostream>
#include<stack>
using namespace std;


int main() {

    // creation of stack
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // check element on top
    cout << "element on top " << st.top() << endl;

    // size
    cout << "size of stack " << st.size() << endl;

    // remove
    st.pop();

    // check empty
    if(st.empty()) {
        cout << "stack is empty" << endl;
    }

    else {
        cout << "stack is not empty" << endl;
    }

    cout << "current size of stack is " << st.size() << endl;

    // printing stack
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout <<endl;
}