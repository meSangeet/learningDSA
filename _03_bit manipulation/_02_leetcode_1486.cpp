#include <bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start) {
    int arr[n]; int ans = 0;
    for(int i = 0; i<n; i++)
    {
        arr[i] = start + 2*i;
        ans = ans^arr[i];
    }    

    return ans;
    }

int main()
{
    
    
    
    return 0;
}