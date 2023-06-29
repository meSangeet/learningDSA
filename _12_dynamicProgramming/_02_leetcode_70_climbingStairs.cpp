#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1, b = 2;
        for(int i = 3; i<=n; i++)
        {
            int temp = a+b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main()
{
    
    return 0;
}