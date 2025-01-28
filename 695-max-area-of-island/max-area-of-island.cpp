class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m, int n, int &cur){
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        visited[i][j] = true;
        cur += grid[i][j];
        for(int p = 0; p<4; p++){
            int ni = i + dir[p].first;
            int nj = j + dir[p].second;
            if(ni >= 0 and ni < m and nj >= 0 and nj < n){
                if(!visited[ni][nj] and grid[ni][nj] != 0){
                    dfs(grid, visited, ni, nj, m, n, cur);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
                int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] != 0 and !visited[i][j]){
                    int cur = 0;
                    dfs(grid, visited, i, j, m, n, cur);
                    ans = max(cur, ans);
                }
            }
        }
        return ans;
    }
};