#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int arr[n];
        int hash[n] = {0};
        for(int i = 0; i<n+1; i++)
        {
            cin>>arr[i];
            arr[i] -= i;
            hash[arr[i]]++;
        }
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(hash[i] != 0)
            {
                int temp = (hash[i]*(hash[i] - 1))/2;
                count += temp;
            }
        }
        cout<<count<<" ";
    }
    
    
    return 0;
}