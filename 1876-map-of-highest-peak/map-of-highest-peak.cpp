class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> ans(n, vector<int> (m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(isWater[i][j] == 1){
                    q.push({0, {i,j}});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            auto temp = q.front();
            q.pop();
            int curx = temp.second.first;
            int cury = temp.second.second;
            int curH = temp.first;
            for(int i = 0; i<4; i++){
                int nx = curx + dir[i].first;
                int ny = cury + dir[i].second;
                if(nx >= 0 && nx < n and ny >= 0 and ny < m){
                    if(ans[nx][ny] == -1){
                        ans[nx][ny] = curH+1;
                        q.push({curH+1, {nx,ny}});
                    }
                }
            }
        }

        return ans;
    }
};