class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rowSum(m,0);
        vector<long long> colSum(n,0);

        long long totalSum = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalSum += grid[i][j];
                //row
                rowSum[i] += grid[i][j];
                //col
                colSum[j] += grid[i][j];
            }
        }
        if(totalSum %2 != 0) return false;

        // horizontal split;
        long long upperSum = 0;
        for(int i=0;i<m-1;i++){
            upperSum += rowSum[i];
            if(upperSum == totalSum-upperSum){
                return true;
            }
        }

        // vertical split
        long long leftSum = 0;
        for(int i=0;i<n-1;i++){
            leftSum += colSum[i];
            if(leftSum == totalSum-leftSum){
                return true;
            }
        }
        return false;
    }
};