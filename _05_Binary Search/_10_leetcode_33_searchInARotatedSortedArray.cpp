#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int pivot(vector<int> &nums)
    {
        int s = 0, l = nums.size() - 1;
        int mid = s + (l-s)/2;
        while(s<l)
        {
            if(nums[mid] > nums[l])
            {
                 s = mid + 1;
            }else{
                if(nums[s] == nums[l]) s = mid+1;
                else l = mid;
            }
            mid = s + (l-s)/2;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int piv = pivot(nums); cout<<piv<<endl;
        int s, l;
        if(target >= nums[piv] && target <= nums[nums.size() - 1])
        {   
            s = piv; l = nums.size()-1;
        }else{
            s = 0; l = piv-1;
        }
        cout<<s<<" "<<l<<endl;
        int mid = s + (l-s)/2;
        while(s <= l)
        {
            if(nums[mid] == target)
            {
                return mid;
            }else if(nums[mid] > target)
            {
                l = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (l-s)/2;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}