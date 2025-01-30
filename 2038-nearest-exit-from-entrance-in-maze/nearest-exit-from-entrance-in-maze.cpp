class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int ex = entrance[0];
        int ey = entrance[1];
        int lev = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        set<pair<int,int>> visited;
        visited.insert({ex,ey});

        q.push({{ex,ey},0});
        while(!q.empty()){
            auto temp = q.front();
            int x = temp.first.first;
            int y = temp.first.second;
            int lev = temp.second;
            if(x != ex || y != ey){
                if(x == 0 || y == 0 || x == n-1 || y == m-1){
                    return lev;
                }
            }
            q.pop();
            for(int i = 0; i<4; i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(visited.count({nx,ny})){
                    //maa chudaye
                }else{
                    if(nx >= 0 and ny >= 0 and nx < n and ny < m){
                        if(maze[nx][ny] == '.'){
                            visited.insert({nx,ny});
                            q.push({{nx,ny}, lev+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};