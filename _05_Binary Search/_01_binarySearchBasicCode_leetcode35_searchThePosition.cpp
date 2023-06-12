#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, l = nums.size() - 1;
        int mid = (s+l)>>1;
        if(target > nums[l]) return l+1;
        while(s<l)
        {
            mid = (s+l)>>1;
            if(nums[mid] > target)
            {
                l = mid;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                return mid;
            }
        }
            return s;
    }
};

int main()
{
    
    
    
    return 0;
}