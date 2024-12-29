class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();
        
        vector<vector<int>> count(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                count[word[j] - 'a'][j]++;
            }
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1];

                if (count[target[i-1] - 'a'][j-1] > 0) {
                    dp[i][j] += dp[i-1][j-1] * count[target[i-1] - 'a'][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[m][n];
    }
};
