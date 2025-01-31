class Solution {
public:
    vector<int>delx , dely;
    void bfs(vector<vector<int>>& grid , int row , int column , vector<vector<int>>&visited , int &island , map<int,int>&mpp){
        int count = 1;
        queue<pair<int,int>>qq;
        qq.push({row , column});
        visited[row][column]=1;
        // doing a bfs to count area of the current island
        while(!qq.empty()){
            int x = qq.front().first , y = qq.front().second;
            qq.pop();
            for(int i = 0 ; i<=3 ; i++){
                int newx=x+delx[i] , newy=y+dely[i];
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && visited[newx][newy]==0 && grid[newx][newy]==1){
                    qq.push({newx,newy});
                    visited[newx][newy]=1;
                    count++;
                }
            }
        }
        // assign all the elements of current island a unique island number
        qq.push({row,column});
        grid[row][column]=island;
        while(!qq.empty()){
            int x = qq.front().first , y = qq.front().second;
            qq.pop();
            for(int i = 0 ; i<=3 ; i++){
                int newx=x+delx[i] , newy=y+dely[i];
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==1){
                    qq.push({newx,newy});
                    grid[newx][newy]=island;
                }
            }
        }
        // link this island number to its area
        mpp[island]=count;
        return;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int max_ = 0;
        vector<vector<int>>visited(grid.size() , vector<int>(grid[0].size(),0));
        map<int,int>mpp; // to store how much area is covered by each island
        int island = 10; // storing unique island name
        delx = {-1,0,1,0} , dely = {0,-1,0,1};
        // finding all distinct islands in current grid and storing how much area each on taken along with assigning them a new unique name
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(visited[i][j]==0&&grid[i][j]){
                    bfs(grid , i , j , visited , island , mpp);
                    island++;
                }
            }
        }

        // for each element = 0 , we flip it and check area now formed connecting the current element
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==0){
                    // c = 1 represents we flipped the current element
                    int c = 1;
                    set<int>ss; // to store what all island names we have considered till now
                    // if island present above that hasnt been counted
                    if(i-1>=0 && ss.find(grid[i-1][j])==ss.end()){
                        c+=mpp[grid[i-1][j]];
                        ss.insert(grid[i-1][j]);
                    }
                    // if island present left that hasnt been counted
                    if(j-1>=0 && ss.find(grid[i][j-1])==ss.end()){
                        c+=mpp[grid[i][j-1]];
                        ss.insert(grid[i][j-1]);
                    }
                    // if island present below that hasnt been counted
                    if(i+1<grid.size() && ss.find(grid[i+1][j])==ss.end()){
                        c+=mpp[grid[i+1][j]];
                        ss.insert(grid[i+1][j]);
                    }
                    // if island present right that hasnt been counted
                    if(j+1<grid[0].size() && ss.find(grid[i][j+1])==ss.end()){
                        c+=mpp[grid[i][j+1]];
                        ss.insert(grid[i][j+1]);
                    }
                    max_ = max(max_  , c);
                }
            }
        }
        // if area = 0 , no 0 element in the grid
        if(max_==0){
            max_ = grid[0].size()*grid.size();
        }
        return max_;
    }
};