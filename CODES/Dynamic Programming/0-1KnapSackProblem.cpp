#include<iostream>
#include<vector>
using namespace std;

// index here = index of last index
int solveUsingRecursion(int weight[], int value[], int index, int capacity) {
    // base case-> only 1 item
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else {
            return 0;
        }
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + solveUsingRecursion(weight, value, index-1, capacity - weight[index]);
    }

    int exclude = solveUsingRecursion(weight, value, index-1, capacity);
    return max(include, exclude);
}

// dp - top down approach - recursion + memoization
int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp) {
    // base case-> only 1 item
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else {
            return 0;
        }
    }

    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    // include and exclude
    int include = 0;
    if(weight[index] <= capacity) {
        include = value[index] + solveUsingMem(weight, value, index-1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveUsingMem(weight, value, index-1, capacity, dp);
    return dp[index][capacity] = max(include, exclude);
}

// dp - bottom up approach - tabulation
int solveUsingTab(int weight[], int value[], int n, int capacity) {
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    // Initialize the first row
    for(int w = 0; w <= capacity; w++) {
        if(weight[0] <= w) {
            dp[0][w] = value[0];
        }
    }

    // Fill the DP table
    for(int index = 1; index < n; index++) {
        for(int wt = 0; wt <= capacity; wt++) {
            int include = 0;
            if(weight[index] <= wt) {
                include = value[index] + dp[index-1][wt - weight[index]];
            }
            int exclude = dp[index-1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }

    return dp[n-1][capacity]; // Return the value at the bottom-right corner
}


// Space optimization - 1
int solveSpaceOpt1(int weight[], int value[], int n, int capacity){
    // Create 2 1D arrays
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + prev[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + prev[wt];
            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
        // Shifting logic (we can forget this)
        prev = curr;
    }
    return prev[capacity];
}

// Space optimization - 2
int solveSpaceOpt2(int weight[], int value[], int n, int capacity){
    // Create 1D array
    vector<int>curr(capacity+1,0);
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >=0; wt--)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + curr[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + curr[wt];
            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main() {

    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingRecursion(weight, value, n-1, capacity);
    cout << ans << endl;


    // dp - top down approach - recursion + memoization
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    int ans2 = solveUsingMem(weight, value, n-1, capacity, dp);
    cout << ans2 << endl;

    // dp - bottom up approach - tabulation
    int ans3 = solveUsingTab(weight, value, n, capacity);
    cout << ans3 << endl;

    // Space optimization - 1
    int ans4 = solveSpaceOpt1(weight,value,n,capacity);
    cout << ans4 << endl;

    // Space optimization - 2
    int ans5 = solveSpaceOpt2(weight,value,n,capacity);
    cout << ans5 << endl;

}