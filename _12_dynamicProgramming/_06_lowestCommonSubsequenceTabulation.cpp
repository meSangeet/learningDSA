#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.length();
        int m=b.length();
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
        for(int i = n-1; i>=0; i--)
        {
            for(int j = m-1; j>=0; j--)
            {
                int ans = 0;
                if(a[i] == b[j])
                {
                    ans = 1 + dp[i+1][j+1];
                }else{
                    ans = max(dp[i][j+1], dp[i+1][j]);
                }
            dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};


int main()
{
    
    return 0;
}