class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        
        dp[n-1][n-1][n-1] = grid[n-1][n-1];
        
        for (int r1 = n-1; r1 >= 0; r1--) {
            for (int c1 = n-1; c1 >= 0; c1--) {
                for (int c2 = n-1; c2 >= 0; c2--) {
                    int r2 = r1 + c1 - c2;
                    if (r2 < 0 || r2 >= n) continue;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    
                    if (r1 == n-1 && c1 == n-1) continue;
                    
                    int result = grid[r1][c1];
                    if (r1 != r2) result += grid[r2][c2];
                    
                    int maxFuture = INT_MIN;
                    if (r1 < n-1) maxFuture = max(maxFuture, dp[r1+1][c1][c2]);
                    if (c1 < n-1) maxFuture = max(maxFuture, dp[r1][c1+1][c2]);
                    if (r1 < n-1 && c2 < n-1) maxFuture = max(maxFuture, dp[r1+1][c1][c2+1]);
                    if (c1 < n-1 && c2 < n-1) maxFuture = max(maxFuture, dp[r1][c1+1][c2+1]);
                    
                    if (maxFuture != INT_MIN) {
                        result += maxFuture;
                        dp[r1][c1][c2] = result;
                    }
                }
            }
        }
        
        return max(0, dp[0][0][0]);
    }
};