class Solution {
private:
    bool isExit(int r, int c, int n, int m, int a, int b){
        
        if(r==0 || c==0 || r==n-1 || c==m-1){
            
            if(r!=a || c!=b){
                return true;
            } 
        }
        return false;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<pair<int, int>, int>> q; // row, col

        q.push({{entrance[0], entrance[1]}, 0});

        maze[entrance[0]][entrance[1]] = '*'; // vis

        int delr[] = {0, 1, 0, -1};
        int delc[] = {1, 0, -1, 0};

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int r = cell.first.first;
            int c = cell.first.second;
            int curr = cell.second;
            

            if(isExit(r, c, n, m, entrance[0], entrance[1])){
                return curr;
            }

            for(int i=0; i<4; i++){
                int nr = delr[i] + r;
                int nc = delc[i] + c;

                if(nr>=0 && nc>=0 && nr<n && nc<m && maze[nr][nc]=='.'){
                    maze[nr][nc] = '*';
                    q.push({{nr, nc}, curr+1});
                }
            }
        }
        return -1;
    }
};