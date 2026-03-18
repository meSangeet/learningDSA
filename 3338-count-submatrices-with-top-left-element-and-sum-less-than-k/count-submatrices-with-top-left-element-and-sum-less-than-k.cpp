class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns
        
        int ans = 0;  // counter for valid submatrices
        
        // Traverse each cell to build prefix sum and check condition
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Add sum of rectangle above current cell (if exists)
                if (i - 1 >= 0)
                    grid[i][j] += grid[i - 1][j];
                
                // Add sum of rectangle left of current cell (if exists)
                if (j - 1 >= 0)
                    grid[i][j] += grid[i][j - 1];
                
                // Subtract diagonal rectangle (added twice in above operations)
                if (i - 1 >= 0 and j - 1 >= 0)
                    grid[i][j] -= grid[i - 1][j - 1];
                
                // Now grid[i][j] contains sum of rectangle from (0,0) to (i,j)
                // Check if this sum is within our limit
                if (grid[i][j] <= k)
                    ++ans;
            }
        }
        
        return ans;
    }
};