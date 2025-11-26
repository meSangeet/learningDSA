class Solution {
public:
    // Recursive function with memoization.
    // i, j = current cell
    // sum = current remainder (sum % k)
    // dp stores memoized results
    int rec(int i,int j,int sum,vector<vector<int>>& grid,int& k,vector<vector<vector<int>>>& dp){
        int n=grid.size(),m=grid[0].size();

        // If we reached bottom-right cell, check if the remainder is 0
        if(i==n-1 && j==m-1) return sum%k==0 ? 1 : 0;

        // Memoized answer already exists
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];

        int right=0,down=0;

        // Move right: update remainder with grid[i][j+1]
        if(j+1<m) right=rec(i,j+1,(sum+grid[i][j+1])%k,grid,k,dp);

        // Move down: update remainder with grid[i+1][j]
        if(i+1<n) down=rec(i+1,j,(sum+grid[i+1][j])%k,grid,k,dp);

        // Store result in dp and return
        return dp[i][j][sum]=(right+down)%1000000007;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();

        // Special case: if k == 1, every path is valid.
        // Simply count number of lattice paths using 2D DP.
        if (k == 1) {
            vector<vector<int>> ways(n, vector<int>(m, 1));
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    ways[i][j] = (ways[i-1][j] + ways[i][j-1]) % 1000000007;
            return ways[n-1][m-1];
        }

        // 3D DP table: dp[i][j][sum] where sum is (current_sum % k)
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));

        // Start from (0,0) with remainder grid[0][0] % k
        return rec(0,0,(grid[0][0])%k,grid,k,dp);
    }
};