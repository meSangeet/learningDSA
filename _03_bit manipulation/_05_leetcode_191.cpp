#include <bits/stdc++.h>
using namespace std;


    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0)
        {
        n = n & (n-1);
        ans++;
        }
        return ans;
    }

int main()
{
    
    
    
    return 0;
}