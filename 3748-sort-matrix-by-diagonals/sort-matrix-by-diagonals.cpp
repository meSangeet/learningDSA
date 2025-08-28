class Solution {
public:
    // Helper function to get elements of a diagonal starting at (row, col)
    vector<int> getDiagonal(vector<vector<int>>& grid, int row, int col) {
        vector<int> diagonal;
        int n = grid.size();
        while (row < n && col < n) {
            diagonal.push_back(grid[row][col]);
            row++;
            col++;
        }
        return diagonal;
    }
    
    // Helper function to set elements of a diagonal starting at (row, col)
    void setDiagonal(vector<vector<int>>& grid, vector<int>& diagonal, int row, int col, int index = 0) {
        int n = grid.size();
        while (row < n && col < n) {
            grid[row][col] = diagonal[index++];
            row++;
            col++;
        }
    }
    
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Handle lower left triangle (including main diagonal)
        for (int i = n-1; i >= 0; i--) {
            vector<int> diagonal = getDiagonal(grid, i, 0);
            sort(diagonal.begin(), diagonal.end(), greater<int>()); // Sort in non-increasing order
            setDiagonal(grid, diagonal, i, 0);
        }
        
        // Handle upper right triangle (excluding main diagonal)
        for (int j = 1; j < n; j++) {
            vector<int> diagonal = getDiagonal(grid, 0, j);
            sort(diagonal.begin(), diagonal.end()); // Sort in non-decreasing order
            setDiagonal(grid, diagonal, 0, j);
        }
        
        return grid;
    }
};
