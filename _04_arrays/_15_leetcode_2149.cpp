#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> even, odd;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        int temp = 0;
        for(int i = 0; i<even.size(); i++)
        {
            nums[temp++] = even[i];
            if(i < odd.size()) nums[temp++] = odd[i];
        }
        return nums;
    }
};


int main()
{
    
    return 0;
}