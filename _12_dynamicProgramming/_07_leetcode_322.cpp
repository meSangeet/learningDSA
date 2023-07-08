#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, -1);
        int n = coins.size();
        dp[0] = 0;
        //dp[i] denotes minimum coins needed to go from i to 0
        for(int i = 1; i<amount+1; i++)
        {
            int miin = INT_MAX; bool flag = true;
            for(int j = 0; j<coins.size(); j++)
            {
                int tar = i - coins[j];
                if(tar >= 0)
                {
                    if(dp[tar] < miin && dp[tar] !=  -1) {
                        miin = dp[tar];
                        flag = false;
                    }
                }
            }
            if(flag) dp[i] = -1;
            else
            dp[i] = miin + 1;
        }
        return dp[amount];
    }
};

int main()
{
    return 0;
}