#include<iostream>
#include<vector>
using namespace std;

class Solution {

    void solve(vector<int> &nums, vector<vector<int>> &output, int ind)
    {
        if(ind == nums.size())
        {
            output.push_back(nums);
            return;
        }

        for(int i = ind; i<nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            solve(nums, output, ind+1);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        solve(nums, output, 0);
        return output;
    }
};

int main()
{
    return 0;
}