class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head) {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        vector<int> ans(ll.size());

        for(int i=0; i<ll.size(); i++) {
            while(!st.empty() && ll[i] > ll[st.top()])  {
                //means, ith element is the next greater of the element index 
                int kids = st.top();
                st.pop();
                ans[kids] = ll[i];
            }

            st.push(i);
        }

        return ans;
    }
};