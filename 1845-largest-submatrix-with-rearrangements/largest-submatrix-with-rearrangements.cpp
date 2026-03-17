class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxSize = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j]) matrix[i][j] += matrix[i-1][j];

        for (auto& row : matrix) {
            sort(row.begin(), row.end(), greater<int>());
            for (int j = 0; j < m; j++)
                maxSize = max(maxSize, row[j] * (j + 1));
        }
        return maxSize;
    }
};