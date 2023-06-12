#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i = 0; i<32; i++)
    {
        if((n&1) == 0)
        {
            ans = ans << 1;
        }else{
            ans = ans << 1;
            ans = ans|1;
        }
         n = n>>1;
    }    
    return ans;
    }

int main()
{
    
    
    
    return 0;
}