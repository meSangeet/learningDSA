#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0, l = (n-1);
        int mid = s + (l-s)/2;
        int ans = -1;
        while(s<=l)
        {
            if(arr[mid] >= arr[mid+1])
            {
                ans = mid;
                l = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (l-s)/2;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}