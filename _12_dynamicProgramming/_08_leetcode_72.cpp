#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        for(int i = 0; i<word1.size()+1; i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0; i<word2.size()+1; i++)
        {
            dp[0][i] = i;
        }


        for(int i = 1; i<word1.size()+1; i++)
        {
            for(int j = 1; j<word2.size()+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    dp[i][j] += 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


int main()
{
    
    return 0;
}
