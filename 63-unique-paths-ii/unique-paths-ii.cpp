class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int n = obstacleGrid.size();
        // int m = obstacleGrid[0].size();
        // if(obstacleGrid[0][0] == 1) return 0;
        // bool flag = false;
        // for(int i = 0; i<m; i++){
        //     if(obstacleGrid[0][i] == 0 && !flag){
        //         obstacleGrid[0][i] = 1;
        //     }else{
        //         obstacleGrid[0][i] = 0;
        //         flag = true;
        //     }
        // }
        // flag = false;
        // for(int i = 1; i<n; i++){
        //     if(obstacleGrid[i][0] == 0 && !flag){
        //         obstacleGrid[i][0] = 1;
        //     }else{
        //         obstacleGrid[i][0] = 0;
        //         flag = true;
        //     }
        // }
        // for(int i = 1; i<n; i++){
        //     for(int j = 1; j<m; j++){
        //         if(obstacleGrid[i][j] == 1){
        //             obstacleGrid[i][j] = 0;
        //         }else{
        //             obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        //         }
        //     }

        // }
        // return obstacleGrid[n-1][m-1];
         int m = obstacleGrid.size();
   int n = obstacleGrid[0].size();
  
   // Edge case: If the starting point or the ending point is an obstacle
   if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
       return 0;
   }
  
   // dp array to store the number of unique paths
   vector<int> dp(n, 0);
   dp[0] = 1; // Starting point
  
   // Traverse through the grid
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < n; j++) {
           if (obstacleGrid[i][j] == 1) {
               dp[j] = 0; // No path through an obstacle
           } else if (j > 0) {
               dp[j] += dp[j - 1]; // Update dp[j] by adding the number of paths from the left
           }
       }
   }
  
   return dp[n - 1]; // The bottom-right corner will have the answer

    }
};