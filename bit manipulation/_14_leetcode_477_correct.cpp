#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] & (1 << i))
                    count += 1;
            }
            ans += count * (nums.size() - count);
        }
        return ans;
    }
};

int main()
{

    return 0;
}