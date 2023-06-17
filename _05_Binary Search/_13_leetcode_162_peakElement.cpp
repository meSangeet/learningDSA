#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, l = nums.size() - 1;
        int mid = s + (l-s)/2;
        while(s<l){
            if((l-s) < 2)
            {
                if(nums[s] > nums[l]) return s;
                else return l;
            }else if(mid > 0 && nums[mid] > nums[mid-1])
            {
                s = mid;
            }else if(mid > 0 && nums[mid-1] > nums[mid])
            {
                l = mid-1;
            }

            mid = s + (l-s)/2;
        }
        return s;
    }
};

int main()
{
    
    return 0;
}