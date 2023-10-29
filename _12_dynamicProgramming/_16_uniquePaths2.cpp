#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<long long int>> dp(r, vector<long long int>(c,0));

        dp[r-1][c-1] =  1;
        for(int i = r-1; i>=0; i--)
        {
            for(int j = c-1; j>=0; j--)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }else{
                    if(i < r-1)
                    {
                        dp[i][j] += dp[i+1][j];
                    }
                    if(j < c-1)
                    {
                        dp[i][j] += dp[i][j+1];
                    }
                }
            }
        }

        return dp[0][0];

    }
};

//main function
int main()
{

    return 0;
}