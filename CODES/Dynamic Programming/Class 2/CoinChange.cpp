// Using Recursion

// class Solution {
// public:
//     int solveUsingRecursion(vector<int>& coins, int amount) {
//         // base case
//         if(amount == 0) return 0;
//         if(amount < 0) return INT_MAX;

//         int mini = INT_MAX;
//         for(int i=0; i<coins.size(); i++) {
//             int ans = solveUsingRecursion(coins, amount - coins[i]);
//             if(ans != INT_MAX) mini = min(mini, 1 + ans);
//         }
//         return mini;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solveUsingRecursion(coins, amount);
//         if(ans == INT_MAX) return -1;
//         else return ans;

//     }
// }; 



// using dp - top down approach[memoization];

class Solution {
public:

    int solveMem(vector<int> & coins, int amount, vector<int>& dp) {
        // base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int ans = solveMem(coins, amount - coins[i], dp);
            if(ans != INT_MAX) mini = min(mini, 1 + ans);
        }
        // step2- store ans in dp array
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        // step 1- create dp array
        vector<int> dp(amount + 1, -1);
        int ans = solveMem(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        else return ans;

    }
}; 



// dp - bottom up approach - tabulation

class Solution {
public:

    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    int ans = dp[i - coins[j]];
                    dp[i] = min(dp[i], 1+ans);
                }
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveTab(coins, amount);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
}; 