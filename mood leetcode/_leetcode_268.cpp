#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int>arr (n,0);
        for(int i = 0; i<nums.size(); i++)
        {
            arr[nums[i]] = 1;
        }
        for(int i = 0; i<nums.size()+1; i++)
        {
            if(!arr[i]) return i;
        }
        return 0;
    }
};

int main()
{
    
    return 0;
}