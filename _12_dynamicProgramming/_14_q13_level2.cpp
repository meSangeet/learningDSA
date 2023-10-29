#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int rob(vector<int>& nums) {
        
       int n = nums.size();
       if(n <= 3)
       {
           return *max_element(nums.begin(), nums.end());
       }
       vector<int> dp1(n,0), dp2(n-1,0);
       dp1[n-1] = nums[n-1];
       dp1[n-2] = max(nums[n-1], nums[n-2]);
       for(int i = n-3; i>=0; i--)
       {
           dp1[i] = max(dp1[i+1], dp1[i+2]+nums[i]);
       }

       dp2[n-2] = nums[n-2];
       dp2[n-3] = max(nums[n-2], nums[n-3]);
       for(int i = n-4; i>=0; i--)
       {
           dp2[i] = max(dp2[i+1], dp2[i+2]+nums[i]);
       }

       return max(dp1[1], dp2[0]);
    }
};

//main function
int main()
{

    return 0;
}