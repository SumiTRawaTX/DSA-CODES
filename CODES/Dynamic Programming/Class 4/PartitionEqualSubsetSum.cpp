class Solution {
public:

    // using recursion
    // bool solveUsingRecursion(int index, vector<int>& nums, int target) {
    //     // base case
    //     int n = nums.size();
    //     if(index >= n) return 0;
    //     if(target < 0) return 0;
    //     if(target == 0) return 1;

    //     bool include = solveUsingRecursion(index + 1, nums, target - nums[index]);
    //     bool exclude = solveUsingRecursion(index + 1, nums, target);
    //     return (include || exclude);
    // }

    // dp - top down approach - recursion + memoization
    //    bool solveUsingMem(int index, vector<int>& nums, int target, vector<vector<int>>& dp) {
    //     // base case
    //     int n = nums.size();
    //     if(index >= n) return 0;
    //     if(target < 0) return 0;
    //     if(target == 0) return 1;

    //     if(dp[index][target] != -1) return dp[index][target];

    //     bool include = solveUsingMem(index + 1, nums, target - nums[index], dp);
    //     bool exclude = solveUsingMem(index + 1, nums, target, dp);
    //     dp[index][target] = (include || exclude);
    //     return dp[index][target];
    // }


    // dp- bottom up approach - tabulation

    // bool solveUsingTabulation(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    //     for(int i = 0; i < nums.size(); i++) {
    //         dp[i][0] = 1;
    //     }

    //     for(int index = n - 1; index >= 0; index--) {
    //         for(int t = 1; t <= target; t++) {
    //             bool include = false; // Corrected declaration here
    //             if(t - nums[index] >= 0)
    //                 include = dp[index + 1][t - nums[index]]; // Removed bool declaration here

    //             bool exclude = dp[index + 1][t];

    //             dp[index][t] = (include || exclude);
    //         }
    //     }
    //     return dp[0][target];
    // }


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // for handling odd case
        if(sum & 1) return false;
        int target = sum/2;
        int index = 0;
        // bool ans = solveUsingRecursion(index,nums, target);

        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        // bool ans = solveUsingMem(index, nums, target, dp);

        bool ans = solveUsingTabulation(nums, target);
        return ans;
    }
};