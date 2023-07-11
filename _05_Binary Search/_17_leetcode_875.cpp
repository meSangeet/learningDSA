#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int k){
        long long int st = 0, curr = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]%mid == 0) st += nums[i]/mid;
            else st += nums[i]/mid  + 1;
        }
        if(st > k) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& nums, int k) {
        int max_ele = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > max_ele) max_ele = nums[i];
        }
        int e = max_ele, s = 1, ans = s;
        int mid = s + (e-s)/2;
        while(s <= e)
        {
            if(isValid(nums, mid, k))
            {
                ans = mid;
                e = mid-1;
            }else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}