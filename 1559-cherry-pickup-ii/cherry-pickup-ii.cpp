class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Initialize 3D DP table
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, INT_MIN)));
        
        // Base case: both robots start from the top row
        dp[0][0][cols-1] = grid[0][0] + grid[0][cols-1];
        
        // Iterate through rows
        for (int row = 1; row < rows; row++) {
            for (int col1 = 0; col1 < cols; col1++) {
                for (int col2 = 0; col2 < cols; col2++) {
                    // Robots can't be in the same column
                    if (col1 == col2) continue;
                    
                    // Calculate cherries collected in this state
                    int cherries = grid[row][col1] + grid[row][col2];
                    
                    // Check all possible previous states
                    for (int prev_col1 = max(0, col1-1); prev_col1 <= min(cols-1, col1+1); prev_col1++) {
                        for (int prev_col2 = max(0, col2-1); prev_col2 <= min(cols-1, col2+1); prev_col2++) {
                            dp[row][col1][col2] = max(dp[row][col1][col2], 
                                                      dp[row-1][prev_col1][prev_col2] + cherries);
                        }
                    }
                }
            }
        }
        
        // Find the maximum value in the last row
        int maxCherries = 0;
        for (int col1 = 0; col1 < cols; col1++) {
            for (int col2 = 0; col2 < cols; col2++) {
                maxCherries = max(maxCherries, dp[rows-1][col1][col2]);
            }
        }
        
        return maxCherries;
    }
};