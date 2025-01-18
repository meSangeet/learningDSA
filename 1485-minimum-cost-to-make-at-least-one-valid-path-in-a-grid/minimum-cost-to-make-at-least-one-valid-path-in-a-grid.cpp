class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dists(rows, vector<int> (cols, INT_MAX));
        dists[0][0] = 0;
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!pq.empty()){
            auto top = pq.top();
            int x = top[1];
            int y = top[2];
            int cost = top[0];
            pq.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx >= 0 && nx < rows and ny >= 0 and ny < cols)
                if(grid[x][y] != i+1){
                    int newCost = cost+1;
                    if(dists[nx][ny] > newCost){
                        dists[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }else{
                    if(dists[nx][ny] > cost){
                        dists[nx][ny] = cost;
                        pq.push({cost, nx, ny});
                    }
                }
            }
        }

        return dists[rows-1][cols-1];
    }
};

//  Brute Force
//class Solution {
//     int ans = INT_MAX;
// public:
//     void backtrack(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int curr, int m, int n){
//         if(i < 0 || j < 0 || i >= m || j >= n) return;
//         if(visited[i][j]) return;
//         if(i == m-1 and j == n-1){
//             ans = min(ans, curr);
//             return;
//         }
//         visited[i][j] = true;
//         // x,y 
//         vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
//         for(int ind = 0; ind<4; ind++){
//             if(grid[i][j] != ind+1){
//                 curr++;
//                 backtrack(i+dir[ind].first, j+dir[ind].second, grid, visited, curr, m, n);
//                 curr--;
//             }else{
//                 backtrack(i+dir[ind].first, j+dir[ind].second, grid, visited, curr, m, n);
//             }
//         }

//         visited[i][j] = false;
//     }

//     int minCost(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<bool>> visited(m, vector<bool> (n, false));
//         backtrack(0,0,grid,visited,0,m,n);
//         return ans;
//     }
// };