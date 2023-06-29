#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = 0; 
        int n = nums.size();
        while(i < n-1 && nums[i] >= nums[i+1])
        {
            i++;
        }
        int temp = INT_MAX;
        if(i == n) return false;
        int bar1 = nums[i];
        i++;
        int bar2 = nums[i];
        i++;
        while(i < n)
        {
            if(nums[i] > bar2) return true;
            else{
                if(nums[i] < bar2 && nums[i] > bar1)
                {
                }else if(nums[i] < bar1 && nums[i] < temp){
                    temp = nums[i];
                }else if(nums[i] <= bar1 && nums[i] > temp){
                    bar1 = temp;
                    bar2 = nums[i];
                }
            }
            i++;
        }
        return false;
    }
};

int main()
{
    
    return 0;
}