#include <bits/stdc++.h>
using namespace std;

 class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != val)
            {
                ans.push_back(nums[i]);
            }
        }
        nums = ans;
        return ans.size();
    }
};   

int main()
{
    
    
    
    return 0;
}

