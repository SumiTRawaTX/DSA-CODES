class Solution {
public:
    // recursion solution -
    int recSolve(int n) {
        // base case
        if(n==1 || n == 0) {
            return n;
        }

        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }


    // dp solution using top down approach
    // Recursion + Memoization
    int topDownSolve(int n, vector<int>& dp) {
        // base case
        if(n == 1 || n == 0) return n;

        // step 3 -
        if(dp[n] != -1) {
            return dp[n];
        }

        // step 2 - replace ans with dp
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        // int ans = recSolve(n);
        // return ans;
   
        // step 1 -  
        vector<int> dp(n+1, -1);
        int ans = topDownSolve(n, dp);
        return ans;
    }
};