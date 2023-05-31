#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int i;
        int size = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 1;)
        {
            if (nums[i] != nums[i + 1])
            {
                ans.push_back(nums[i]);
                i++;
            }
            else
            {
                i = i + 2;
            }
        }
        if (nums[size - 1] != nums[size - 2])
        {
            ans.push_back(nums[size - 1]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}