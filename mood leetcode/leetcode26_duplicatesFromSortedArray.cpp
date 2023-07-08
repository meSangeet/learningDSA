#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newi ;
        int prev = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == prev) continue;
            newi.push_back(nums[i]);
            prev = nums[i];
        }
        int k = newi.size();
        nums = newi;
        return k;
    }
};
   
int main()
{
    
    
    
    return 0;
}

