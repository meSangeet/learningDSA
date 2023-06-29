#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int fib(int n) {
        int prev2 = 0, prev = 1;
        if(n<=1) return n;
        for(int i = 2; i<=n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main()
{
    
    return 0;
}