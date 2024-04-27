class Solution {
public:
    int MOD = 1000000007;
    // int solveUsingRecursion(int n, int k, int target) {
    //     // base case
    //     if(n < 0) return 0;
    //     if(n == 0 && target == 0) return 1;
    //     if(n == 0 && target != 0) return 0;
    //     if(n != 0 && target == 0) return 0;

    //     int ans = 0;
    //     for(int i=0; i<=k; i++) {
    //         ans += solveUsingRecursion(n-1, k, target - i);
    //     }
    //     return ans;
    // }


    // int solveUsingMem(int n, int k, int target, vector<vector<int>>& dp) {
    //     // base case
    //     if (n < 0 || target < 0) return 0;
    //     if (n == 0 && target == 0) return 1;
    //     if (n == 0 && target != 0) return 0;

    //     if (dp[n][target] != -1) return dp[n][target];

    //     int ans = 0;
    //     for (int i = 1; i <= k; i++) {
    //         ans = (ans % MOD + solveUsingMem(n - 1, k, target - i, dp) % MOD) % MOD;
    //     }
    //     dp[n][target] = ans;
    //     return dp[n][target];
    // }

    // int solveUsingTabulation(int n, int k, int target) {
    //     vector<vector<long long int>> dp(n+1, vector<long long int>(target + 1, 0));
    //     dp[0][0] = 1;

    //     for(int index = 1; index <= n; index++) {
    //         for(int t = 1; t <= target; t++) {
    //             long long int ans = 0;
    //             for(int i = 1; i <= k; i++) {
    //                 long long int recAns = 0;
    //                 if(t - i >= 0) {
    //                     recAns = dp[index - 1][t - i];
    //                 }
    //                 ans = (ans % MOD + recAns % MOD) % MOD;
    //             }
    //             dp[index][t] = ans;
    //         }
    //     }
    //     return dp[n][target];
    // }

    int solveUsingSO(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        for(int index = 1; index <= n; index++) {
            for(int t = 1; t <= target; t++) {
                long long int ans = 0;
                for(int i = 1; i <= k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0) {
                        recAns = prev[t - i];
                    }
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] = ans;
            }
            //shift
            prev = curr;
        }
        return prev[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solveUsingMem(n, k, target, dp);

        // return solveUsingTabulation(n, k, target);

        return solveUsingSO(n, k, target);
    }

};