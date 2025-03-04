class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

        // Base case: Single character substrings are palindromes of length 1
        for (int i = 0; i < n; i++) {
            for (int cost = 0; cost <= k; cost++) {
                dp[i][i][cost] = 1;
            }
        }

        // Iterate over substring lengths from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                for (int cost = 0; cost <= k; cost++) {
                    // Case 1: Exclude s[i] or s[j]
                    dp[i][j][cost] = max(dp[i + 1][j][cost], dp[i][j - 1][cost]);

                    // Case 2: If s[i] and s[j] are converted to be the same
                    int changeCost = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
                    if (cost >= changeCost) {
                        dp[i][j][cost] = max(dp[i][j][cost], 2 + dp[i + 1][j - 1][cost - changeCost]);
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
