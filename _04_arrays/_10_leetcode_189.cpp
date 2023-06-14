#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans = nums;
        for(int i = 0; i<nums.size(); i++)
        {
            ans[(i+k)%nums.size()] = nums[i];
        }
        nums = ans;
    }
};

int main()
{
    
    return 0;
}