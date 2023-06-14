#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:

    int gcd(int a, int b)
    {
        if(a == b)  return a;
        if(a>b) return gcd(b, a-b);
        return gcd(a, b-a);
    }

    int findGCD(vector<int>& nums) {
        int max = INT_MIN; int min = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }

        int ans = gcd(min, max);
        return ans;
    }
};

int main()
{
    
    return 0;
}