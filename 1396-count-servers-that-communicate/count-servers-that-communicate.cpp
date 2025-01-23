class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int rc = 0, cc = 0;
                    for(int k = 0; k<n; k++){
                        if(grid[k][j] == 1) cc++;
                    }
                    for(int k = 0; k<m; k++){
                        if(grid[i][k] == 1) rc++;
                    }
                    if(rc > 1 || cc > 1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};