#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lmin;
        int miin = INT_MAX, maax = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < miin) miin = nums[i];
            lmin.push_back(miin);
        }
        deque<int> rmax;
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(nums[i] > maax) maax = nums[i];
            rmax.push_front(maax);
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > lmin[i] && nums[i]<rmax[i]) return true;
        }
        return false;
    }
};

int main()
{
    
    return 0;
}