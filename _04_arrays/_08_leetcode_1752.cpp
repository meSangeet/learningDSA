#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool check(vector<int>& nums) {
        int prev = INT_MIN;
        int count = 1;
        int mini = INT_MAX; int i;
        for(i = 0; i<nums.size(); i++)
        {
           if(nums[i] >= prev) 
           {
               mini = min(mini, nums[i]);
               prev = nums[i];
           }else{
               goto x;
           }
        }

        x:
        prev = INT_MIN;
        while(i<nums.size())
        {
            if(nums[i] > mini){ return false; }
            else if(prev>nums[i]) return false;
            prev = nums[i];
            i++;
        }

        return true;
    }
};

int main()
{
    
    return 0;
}