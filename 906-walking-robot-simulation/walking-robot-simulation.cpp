class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>, int> m;
        for(int i = 0; i<obstacles.size(); i++)
        {
            m[{obstacles[i][0], obstacles[i][1]}] = 1;
        }

        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int ans = 0;
        int x = 0, y = 0;
        int dir = 0;

        for(int i = 0; i<commands.size(); i++)
        {
            int command = commands[i];

            if(command == -2)
            {
                dir += 3;
                dir %= 4;
            }else if(command == -1)
            {
                dir++;
                dir %= 4;
            }else{
                for(int p = 1; p<=command; p++)
                {
                    int newx = directions[dir].first + x;
                    int newy = directions[dir].second + y;
                    if(m[{newx, newy}] == 1)
                    {
                        break;
                    }

                    x = newx;
                    y = newy;

                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};