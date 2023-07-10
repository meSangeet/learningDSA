#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1, e = sqrt(num);
        int mid = (s+e)>>1;
        while(s<=e)
        {
            if(pow(mid,2) == num) return true;
            if(pow(mid, 2) < num) s = mid+1;
            else if(pow(mid, 2) > num) e = mid-1;
            mid = (s+e) >> 1;
        }
        return false;
    }
};

int main()
{
    
    return 0;
}