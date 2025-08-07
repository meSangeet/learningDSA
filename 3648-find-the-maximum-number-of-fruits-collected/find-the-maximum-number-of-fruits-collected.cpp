class Solution {
private:
    static const int INVALID = -1e9;
    int gridSize;
    
    bool isValidPosition(int row, int col) {
        return row >= 0 && row < gridSize && col >= 0 && col < gridSize;
    }
    
    bool isDestination(int row, int col) {
        return row == gridSize - 1 && col == gridSize - 1;
    }
    
    bool isOnMainDiagonal(int row, int col) {
        return row == col;
    }
    
    int collectFruits(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (!isValidPosition(row, col)) {
            return INVALID;
        }
        
        if (isDestination(row, col)) {
            return 0;
        }
        
        if (isOnMainDiagonal(row, col)) {
            return INVALID;
        }
        
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        
        int currentFruits = grid[row][col];
        
        int maxFromNextMoves = max({
            collectFruits(row - 1, col + 1, grid, memo),
            collectFruits(row, col + 1, grid, memo),
            collectFruits(row + 1, col + 1, grid, memo)
        });
        
        return memo[row][col] = currentFruits + maxFromNextMoves;
    }
    
    int calculateDiagonalPath(const vector<vector<int>>& fruits) {
        int totalFruits = 0;
        for (int i = 0; i < gridSize; i++) {
            totalFruits += fruits[i][i];
        }
        return totalFruits;
    }
    
    int calculateBottomPath(const vector<vector<int>>& fruits) {
        vector<vector<int>> memo(gridSize, vector<int>(gridSize, -1));
        return collectFruits(gridSize - 1, 0, fruits, memo);
    }
    
    int calculateTopPath(vector<vector<int>>& fruits) {
        transposeMatrix(fruits);
        
        vector<vector<int>> memo(gridSize, vector<int>(gridSize, -1));
        int result = collectFruits(gridSize - 1, 0, fruits, memo);
        
        transposeMatrix(fruits);
        
        return result;
    }
    
    void transposeMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < gridSize; i++) {
            for (int j = i + 1; j < gridSize; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        gridSize = fruits.size();
        
        int child1Fruits = calculateDiagonalPath(fruits);
        int child2Fruits = calculateBottomPath(fruits);
        int child3Fruits = calculateTopPath(fruits);
        
        return child1Fruits + child2Fruits + child3Fruits;
    }
};