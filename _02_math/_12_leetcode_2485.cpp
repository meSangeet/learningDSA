#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int pivotInteger(int n) {
        int arrl[n+1],arrr[n+1];
        arrl[0] = 0;
        arrr[n] = n;
        if(n == 1)  return 1;
        for(int i = 1; i<n+1; i++)
        {
            arrl[i] = i+arrl[i-1];
        }
        for(int i = n-1; i>=0; i--)
        {
            arrr[i] = arrr[i+1]+i;
        }
        if(n == 1) return 1;
        for(int i = 1; i<n+1; i++)
        {
            if(arrl[i] == arrr[i])
            return i;
        }
        return -1;
    }
};
int main()
{
    
    return 0;
}