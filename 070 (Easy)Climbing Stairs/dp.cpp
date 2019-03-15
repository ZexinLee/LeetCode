class Solution {
public:
    // Func(i, n) = F(i + 1, n) + F(i + 2, n)
    // Func(0, n)
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};