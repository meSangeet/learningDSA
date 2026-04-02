class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                for(int k = 0; k <= 2; k++) {

                    if(i == n - 1 && j == m - 1) {
                        if(coins[i][j] >= 0)
                            dp[i][j][k] = coins[i][j];
                        else {
                            dp[i][j][k] = coins[i][j]; // no neutralize
                            if(k < 2)
                                dp[i][j][k] = max(dp[i][j][k], 0); // neutralize
                        }
                        continue;
                    }

                    int bestNext = INT_MIN;

                    if(i + 1 < n)
                        bestNext = max(bestNext, dp[i + 1][j][k]);
                    if(j + 1 < m)
                        bestNext = max(bestNext, dp[i][j + 1][k]);

                    int ans = coins[i][j] + bestNext;

                    // try neutralizing if negative
                    if(coins[i][j] < 0 && k < 2) {
                        int bestNextNeutral = INT_MIN;

                        if(i + 1 < n)
                            bestNextNeutral = max(bestNextNeutral, dp[i + 1][j][k + 1]);
                        if(j + 1 < m)
                            bestNextNeutral = max(bestNextNeutral, dp[i][j + 1][k + 1]);

                        ans = max(ans, bestNextNeutral); // 0 added
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};