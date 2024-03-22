int countRev (string s)
{
 if(s.size() % 2 != 0) return -1; // Check if the string length is odd, return -1 if so

    int ans = 0;
    stack<char> st;

    for(char ch : s) {
        if(ch == '{') {
            st.push(ch);
        } else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    // Now, the stack contains only unbalanced braces
    while(!st.empty()) {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();

        if(a == b) {
            ans++; // Increment count for one reversal
        } else {
            ans += 2; // Increment count for two reversals
        }
    }
    
    return ans;
    
}