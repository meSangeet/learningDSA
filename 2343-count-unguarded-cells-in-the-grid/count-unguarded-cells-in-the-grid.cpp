class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto x : guards){
            grid[x[0]][x[1]] = 1;
        }
        for(auto x : walls){
            grid[x[0]][x[1]] = 2;
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k = i-1; k >= 0; k--){
                        if(grid[k][j] == 2 || grid[k][j] == 1){
                            break; 
                        }
                        // cout<<k<<" "<<j<<endl;
                        grid[k][j] = 4;
                    }

                    for(int k = i+1; k<m; k++){
                        if(grid[k][j] == 2 || grid[k][j] == 1){
                            break;
                        }
                        // cout<<k<<" "<<j<<endl;
                        grid[k][j] = 4;
                    }

                    for(int k = j+1; k<n; k++){
                        if(grid[i][k] == 2 || grid[i][k] == 1) break;
                        // cout<<i<<" "<<k<<endl;
                        grid[i][k] = 4;
                     }

                    for(int k = j-1; k>=0; k--){
                        if(grid[i][k] == 2 || grid[i][k] == 1) break;
                        // cout<<i<<" "<<k<<endl;
                        grid[i][k] = 4;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};