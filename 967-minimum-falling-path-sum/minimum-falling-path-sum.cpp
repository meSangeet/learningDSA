class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] += min({j > 0 ? matrix[i+1][j-1] : INT_MAX,
                                     matrix[i+1][j],
                                     j < n-1 ? matrix[i+1][j+1] : INT_MAX});
            }
        }
        
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};