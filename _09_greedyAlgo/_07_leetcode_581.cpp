#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int s = INT_MIN, l = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != temp[i])
            {
                if(s == INT_MIN) s = i;
                else l = i;
            }

        }
        if(l == 0) return 0;
        return (l-s+1);
    }
};

int main()
{
    
    return 0;
}