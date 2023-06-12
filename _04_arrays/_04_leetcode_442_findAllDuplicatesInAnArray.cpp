#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> m;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++)
        {
            m[nums[i]] += 1;
            if(m[nums[i]] == 2)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    
    
    
    return 0;
}