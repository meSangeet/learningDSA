//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();  // Number of rows
        if (n == 0) return 0; // If the grid is empty
        int m = grid[0].size();  // Number of columns

        int islandCount = 0;

        // Perform DFS for each unvisited land cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    // If we find a piece of land, we start DFS
                    dfs(grid, i, j, n, m);
                    islandCount++;  // Increment the island count
                }
            }
        }

        return islandCount;
    }

private:
    // DFS function to mark all connected land cells as visited
    void dfs(vector<vector<char>>& grid, int row, int col, int n, int m) {
        // If the cell is out of bounds or it's water, return
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '0') return;

        // Mark the current cell as visited by setting it to '0'
        grid[row][col] = '0';

        // Define the 8 directions (up, down, left, right, and 4 diagonals)
        int dirX[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dirY[] = {0, 0, -1, 1, -1, 1, -1, 1};

        // Explore all 8 directions
        for (int i = 0; i < 8; ++i) {
            dfs(grid, row + dirX[i], col + dirY[i], n, m);
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends