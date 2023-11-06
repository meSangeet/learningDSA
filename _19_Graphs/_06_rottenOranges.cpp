#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};
        int totalOranges = 0, rottenOranges = 0;
        queue<pair<pair<int,int>, int>> q; //queue to store rotten oranges
        bool flag = false; //to check whether the grid contain any fresh orange or not
        int ans = -1;
        int rows = grid.size(), columns = grid[0].size();
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<columns; j++)
            {
                if(grid[i][j] == 1)
                {
                    flag = true;
                    totalOranges++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    rottenOranges++;
                    totalOranges++;
                }
            }
        }

        //edge cases
        if(!flag) return 0;
        if(q.empty()) return -1;

        ans = 0;
        //general case
        while(!q.empty())
        {
            auto rot = q.front();
            q.pop();
            int curLevel = rot.second;
            int R = rot.first.first;
            int C = rot.first.second;

            for(int i = 0; i<4; i++)
            {
                 int newRow = R + r[i], newCol = C + c[i];
                 if((newRow >= 0 && newRow < rows) && (newCol >= 0 && newCol < columns))
                 {
                     if(grid[newRow][newCol] == 1)
                     {
                         rottenOranges++;
                         grid[newRow][newCol] = 2;
                         q.push({{newRow, newCol}, curLevel+1});
                         ans = max(ans, curLevel+1);
                     }
                 }
            }
        }
        if(totalOranges != rottenOranges)
        {
            return -1;
        }
        return ans;
    }
};

//main function
int main()
{

    return 0;
}