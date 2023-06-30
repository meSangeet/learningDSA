#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

bool recur(vector<int> &nums, vector<int> &dp, int ind)
{
    if (ind == nums.size() - 1)
        return true;
    if (ind < nums.size())
    {
        bool flag = false;
        for (int i = 1; i <= ind; i++)
        {
            int temp = ind + i;
            if (temp < nums.size())
            {
                if (dp[temp] == -1)
                    goto x;
                if (dp[temp] == 1)
                {
                    return true;
                }
                if (dp[temp] == 0)
                {
                    dp[temp] = recur(nums, dp, temp);
                }
            }
        x:
        }
        return false;
    }
}
bool canJump(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    return recur(nums, dp, 0);
}

int main()
{

    return 0;
}