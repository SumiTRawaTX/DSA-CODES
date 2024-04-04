#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string str) {
    stack<char> st;
    
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if(ch == ')') {
            int operaterCount = 0;
            while(st.top() != '(') { 
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                    operaterCount++;
                }
                st.pop();
            }
            // yha per aap tabhi pohochoge jab
            // aapke stack k top pr ek opening bracket hoga
            st.pop();
            
            if(operaterCount == 0) {
                return true;
            }
        }
    }
    // agar main yaha tk pohocha hun
    // iska matlab k har ek bracket k pair k beech me
    // ek operator pkk mila hai
    return false;
}

int main() {

    string str = "(((a+b)*(c+d)))";
    bool ans = checkRedundant(str);

    if(ans == true) {
        cout << "Redundant Bracket Present" << endl;
    }

    else {
        cout << "Redundant Bracket Not present" << endl;
    }

    return 0;
}