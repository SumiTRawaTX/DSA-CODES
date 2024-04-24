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

    int spaceOptSolve(int n) {

        // step 2- observe base case in above solution
        int prev2 = 0;
        int prev1 = 1;

        if(n == prev2) return prev2;
        if(n == prev1) return prev1;

        int curr;
        // step 3 - 
        for(int i=2; i<=n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int fib(int n) {
        return spaceOptSolve(n);
    }
};