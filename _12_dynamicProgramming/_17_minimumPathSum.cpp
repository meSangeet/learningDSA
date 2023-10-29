#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<long long int>> dp(r, vector<long long int>(c,0));
        dp[r-1][c-1] = grid[r-1][c-1];
        for(int i = r-1; i>=0; i--)
        {
            for(int j = c-1; j>=0; j--)
            {
                int x = INT_MAX, y = INT_MAX;

                if(i < r-1)
                {
                    x = dp[i+1][j];
                }

                if(j <  c-1)
                {
                    y = dp[i][j+1];
                }
                if(i != (r-1) || j != (c-1))
                dp[i][j] = grid[i][j] + min(x,y);
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