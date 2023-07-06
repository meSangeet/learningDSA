#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i >= s1.length() || j >= s2.length())
        return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j])
        {
             ans = 1 + lcs(s1, s2, i+1, j+1, dp);
        }else{
            ans = max(lcs(s1,s2,i+1,j, dp), lcs(s1,s2,i,j+1, dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        return lcs(text1, text2, 0, 0, dp);
    }
};

int main()
{
    
    return 0;
}