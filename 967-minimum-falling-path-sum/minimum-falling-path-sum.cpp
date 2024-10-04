class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Initialize the bottom row
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }
        
        // Build the dp table from bottom to top
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] + min({j > 0 ? dp[i+1][j-1] : INT_MAX,
                                               dp[i+1][j],
                                               j < n-1 ? dp[i+1][j+1] : INT_MAX});
            }
        }
        
        // Return the minimum value in the top row
        return *min_element(dp[0].begin(), dp[0].end());
    }
};