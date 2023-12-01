class Solution {
public:

    int numSquareHelper(int n) {
        if (n == 0) return 0;
        if (n < 0) return INT_MAX;

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while (i <= end) {
            int perfectSquare = i * i;
            int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
            if (numberOfPerfectSquares != INT_MAX && numberOfPerfectSquares < ans) {
                ans = numberOfPerfectSquares;
            }
            ++i;
        }
        return ans;
    }

    int numSquares(int n) {
        return numSquareHelper(n);
    }
};