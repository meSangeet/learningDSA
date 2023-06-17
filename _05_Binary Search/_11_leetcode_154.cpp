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
        cout<<s<<" "<<l<<" "<<mid<<endl;
        if(nums[mid] > nums[l]){
            s = mid+1;
        }else if(nums[mid] < nums[l]){
            l = mid;
        }else{
            int temp = mid;
            while( temp<nums.size()-1  && nums[temp] >= nums[mid] && temp>0)
            {
                if(nums[temp+1] < nums[temp]) return nums[temp+1];
                temp++;
            }
            temp = mid;
            while( temp >= 0 && nums[temp] <= nums[mid])
            {
                if(temp == 0) if(nums[0] <= nums[1]) return nums[0];
                if(nums[temp-1] > nums[temp]) return nums[temp];
                temp--;
            }
            s++;
        }

        mid = (s+l)/2;
    }
    return nums[l];
}
};

int main()
{
    
    return 0;
}