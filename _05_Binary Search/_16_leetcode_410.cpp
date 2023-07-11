#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int k){
        int st = 1, curr = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(curr + nums[i] > mid){
                curr = nums[i];
                st++;
            }else{
                curr += nums[i];
            }
        }

        if(st > k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0, max_ele = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > max_ele) max_ele = nums[i];
            sum += nums[i];
        }
        int s = max_ele, e = sum, ans = s;
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