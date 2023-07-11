#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int n) {
    return true;
}
class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n, ans;
        int mid = s + (e-s)/2;
        while(s <= e)
        {
            if(isBadVersion(mid)) {
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}