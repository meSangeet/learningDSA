#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
int findMin(vector<int> &nums)
{
    int s = 0, l = nums.size() - 1;
    int mid = (s+l)/2;
    while(s<l)
    {
        if(nums[mid] > nums[l]){
            s = mid+1;
        }else if(nums[mid] < nums[l]){
            l = mid;
        }else{
            int temp = mid;
            while( temp<nums.size()-1  && nums[temp] >= nums[mid] && temp>0)
            {
                if(nums[temp+1] < nums[temp]) return temp+1;
                temp++;
            }
            temp = mid;
            while( temp >= 0 && nums[temp] <= nums[mid])
            {
                if(temp == 0) if(nums[0] <= nums[1]) return 0;
                if(nums[temp-1] > nums[temp]) return temp;
                temp--;
            }
            s++;
        }

        mid = (s+l)/2;
    }
    return l;
}
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() == 1){
         if(nums[0] == target) return true;
         return false;   
        }
        if(nums.size() == 2){
            if(nums[0] == target || nums[1] == target) return true;
            return false;
        }
        int min = findMin(nums);
        cout<<min<<endl;
        int s, l, mid;
        if(target <= nums[nums.size() - 1]){
        s = min; l = nums.size()-1;
        }else{
            s = 0;
            l = min-1;
        }
        mid = s + (l-s)/2;

        while(s<=l)
        {
            if(nums[mid] == target) return true;
            else if(nums[mid] > target){
                l = mid - 1;
            }else{
                s = mid+1;
            }
            mid = (s+l)>>1;
        }
    return false;
    }
};

int main()
{
    
    return 0;
}