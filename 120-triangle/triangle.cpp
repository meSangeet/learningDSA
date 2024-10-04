class Solution {
public:
    int minimumTotalHelper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo) {
        if (row == triangle.size() - 1) return triangle[row][col];
        if (memo[row][col] != INT_MAX) return memo[row][col];
        
        return memo[row][col] = triangle[row][col] + min(minimumTotalHelper(triangle, row+1, col, memo),
                                                         minimumTotalHelper(triangle, row+1, col+1, memo));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        return minimumTotalHelper(triangle, 0, 0, memo);
    }
};