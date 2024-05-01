class Solution {
public:

    //  quareHelper(int n, vector<int>& dp) {
    //         if (n == 0) return 0;
    //         if (n < 0) return 0;

    //         if(dp[n] != -1) return dp[n];

    //         int ans = INT_MAX;
    //         int i = 1;
    //         int end = sqrt(n);
    //         while (i <= end) {
    //             int perfectSquare = i * i;
    //             int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare, dp);
    //             if (numberOfPerfectSquares < ans) {
    //                 ans = numberOfPerfectSquares;
    //             }
    //             ++i;
    //         }
    //         // return ans;
    //         dp[n] = ans;
    //         return dp[n];
    //     }   

    int numSquareHelperBU(int n, vector<int>& dp) {
        // if (n == 0) return 0;
        // if (n < 0) return 0;

        // if(dp[n] != -1) return dp[n];

        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            int ans = INT_MAX;
            int start = 1;
            int end = sqrt(i);
            while (start <= end) {
                int perfectSquare = start * start;
                int numberOfPerfectSquares = 1 + dp[i - perfectSquare];
                if (numberOfPerfectSquares < ans) {
                    ans = numberOfPerfectSquares;
                }
                ++start;
            }   
            dp[i] = ans;
            // return ans;
            //dp[n] = ans;
            // return dp[n];
        }
        return dp[n];
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        // return numSquareHelper(n, dp);
        return numSquareHelperBU(n, dp) - 1;
    }
};