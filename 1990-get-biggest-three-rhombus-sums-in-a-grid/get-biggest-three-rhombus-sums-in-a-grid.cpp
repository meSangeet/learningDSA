class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<int> s;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int lef = j+1;
                int ri = n-j;
                int rowsBelow = m-i;
                if(rowsBelow%2 == 1) rowsBelow++;
                rowsBelow /= 2;
                int dim = min({lef, ri, rowsBelow});
                
                for(int dimension = 1; dimension <= dim; dimension++){
                    int coun = 0;
                    int sum = 0;
                    int x = i, y = j;
                    while(coun < dimension){
                        sum += grid[x][y];
                        x++;
                        y--;
                        coun++;
                    }
                    coun = 0;
                    x--; y++;
                    x++; y++;
                    while(coun < dimension-1){
                        sum += grid[x][y];
                        x++;
                        y++;
                        coun++;
                    }
                    x--;
                    y--;
                    x--; y++;
                    coun = 0;
                    while(coun < dimension-1){
                        sum += grid[x][y];
                        x--;
                        y++;
                        coun++;
                    }
                    x++;
                    y--;
                    coun = 0;
                    x--; y--;
                    while(coun < dimension-2){
                        sum += grid[x][y];
                        x--;
                        y--;
                        coun++;
                    }
                    s.push(sum); 
                }
            }
        }

        if(s.size() < 3){
            vector<int> ans;
            while(!s.empty()){
                if(ans.size() == 0){
                    ans.push_back(s.top());
                    s.pop();
                }else{
                    if(ans.back() != s.top()){
                        ans.push_back(s.top());
                    }
                    s.pop();
                }
            }

            return ans;
        }

        vector<int> ans;
        while(!s.empty() and ans.size() < 3){
            if(ans.size() == 0){
                ans.push_back(s.top());
                s.pop();
            }else{
                if(ans.back() != s.top()){
                    ans.push_back(s.top());
                }
                s.pop();
            }
        }
        return ans;
    }
};