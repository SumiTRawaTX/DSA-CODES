class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        //step 1 - push all person into stack
        for(int i=0; i<n; i++) {
            st.push(i);
        }
        
        //step 2 - run discord method, to get a mightBeCelebrity
        while(st.size() != 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            // if a know b?
            if(M[a][b]) {
                // a is not celebrity, b might be
                st.push(b);
            }
            else {
                // b is not celebrity, a might be
                st.push(a);
            }
        }
        
        // step 3 - check that person is actually celebrity?
        int mightBeCelebrity = st.top(); st.pop();
        
        // cel should not know anyone
        for(int i=0; i<n; i++) {
            if(M[mightBeCelebrity][i] != 0) {
                return -1;
            }
        }
        
        // every one should know cel
        for(int i=0; i<n; i++) {
            if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity) {
                return -1;
            }
        }
        
        return mightBeCelebrity;
    }
};