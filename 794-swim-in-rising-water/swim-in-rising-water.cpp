class Solution {
public:
    bool possible(vector<vector<int>> &grid, int n, vector<vector<bool>> &visited, int mid){
        visited[0][0] = true;
        queue<pair<int,int>> q;
        if(grid[0][0] > mid) return false;
        q.push({0,0});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            if(x == n-1 and y == n-1) return true;
            q.pop();
            //going right
            int nx = x+1;
            int ny = y;
            if(nx < n and visited[nx][y] == false and grid[nx][y] <= mid){
                visited[nx][ny] = true;
                q.push({nx,y});
            }

            //going down
            nx = x;
            ny = y-1;
            if(ny >= 0 and visited[nx][ny] == false and grid[nx][ny] <= mid){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }

            //going up
            nx = x;
            ny = y+1;
            if(ny < n and visited[nx][ny] == false and grid[nx][ny] <= mid){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }

            //going left
            nx = x-1;
            ny = y;
            if(nx >= 0 and visited[nx][ny] == false and grid[nx][ny] <= mid){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0, h = n*n;
        int ans = n*n;
        while(l <= h){
            int mid = l + (h - l)/2;
            vector<vector<bool>> visited(n, vector<bool> (n, false));
            if(possible(grid, n, visited, mid)){
                h = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};