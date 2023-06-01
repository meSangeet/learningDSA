#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

// again tle 37/46

class Solution {
public:
    int setBits(int number)
    {
        int ans = 0;
        while(number)
        {
            ans += (number&1) == 1;
            number >>= 1;
        }
        return ans;
    }
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return 0;
        }
        int sum = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                int xoor = (nums[i]^nums[j]);
                sum += setBits(xoor);
            }
        }
        return sum;
    }
};

int main()
{
    
    
    
    return 0;
}