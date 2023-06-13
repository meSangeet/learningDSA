#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        if(nums.size() == 0) return 0;
        for(int i = 0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        int count = 1;
        int maax = 1;
        int prev = INT_MIN;
        for(auto x:s)
        {
            if(x == prev+1)
            {
                count++;
                if(count > maax) maax = count;
            }else{
                count = 1;
            }

            prev = x;
        }

        return maax;
    }
};

int main()
{
    
    return 0;
}