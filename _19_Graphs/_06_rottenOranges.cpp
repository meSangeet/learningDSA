class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int ans = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        vector<int> a = {1,0,-1,0};
        vector<int> b = {0,1,0,-1};

        while(!q.empty())
        {
            pair<int,int> coord = q.front().first;
            int lev = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++)
            {
                int nr = coord.first + a[i];
                int nc = coord.second + b[i];
                if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 1)
                {
                    q.push({{nr,nc},lev+1});
                    grid[nr][nc] = 2;
                    ans = lev+1;
                }
            }
        }

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};