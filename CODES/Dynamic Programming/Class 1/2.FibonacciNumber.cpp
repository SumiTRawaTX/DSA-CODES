class Solution {
public:

    int recSolve(int n) {
        // base case
        if(n==1 || n == 0) {
            return n;
        }
        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }
    // Bottom UP Approach - Tabulation
    int BottomUpSolve(int n) {
        // step 1- create dp array
        vector<int> dp(n+1, -1);
        // step 2- observe base case in above solution
        dp[0] = 0;
        if(n == 0) return dp[0];
        dp[1] = 1;
        // step 3 - 
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fib(int n) {
        return BottomUpSolve(n);
    }
};