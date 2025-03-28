class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> que;
        for(int i = 0; i < queries.size(); i++){
            que.push_back({queries[i], i});
        }
        sort(que.begin(), que.end());

        int count = 0;
        vector<int> ans(que.size());

        int mx = grid.size();
        int my = grid[0].size();
        vector<vector<bool>> vis(mx, vector<bool>(my, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        for(auto q : que){
            int no = q.first;
            while(!pq.empty() && pq.top()[0] < no){
                count++;
                auto to = pq.top();
                pq.pop();
                int x = to[1];
                int y = to[2];

                for(int i = 0; i < 4; i++){
                    int dx = dir[i].first;
                    int dy = dir[i].second;
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx < 0 || nx >= mx || ny < 0 || ny >= my) continue;
                    if(!vis[nx][ny]){
                        pq.push({grid[nx][ny], nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            ans[q.second] = count;
        }
        return ans;
    }
};
