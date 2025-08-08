class Solution {
public:
    vector<vector<double>> dp;

    // Recursive function with memoization
    double f(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] != -1) return dp[a][b];

        return dp[a][b] = 0.25 * (
            f(a - 4, b) +
            f(a - 3, b - 1) +
            f(a - 2, b - 2) +
            f(a - 1, b - 3)
        );
    }

    double soupServings(int n) {
        // Optimization: For large n, the probability approaches 1
        if (n >= 4800) return 1.0;

        n = (n + 24) / 25; // Convert ml to "units of 25 ml"
        dp.resize(n + 1, vector<double>(n + 1, -1));

        return f(n, n);
    }
};