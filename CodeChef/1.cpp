#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    long long int n; cin>>n;
    long long q; cin>>q;
        
       vector<long long> arr;
       for(long long i = 0; i<n; i++)
       {
        long long p; cin>>p;
        arr.push_back(p);
       }

       sort(arr.begin(), arr.end());
       while(q--)
       {
        long long k; cin>>k;
        k--;
        long long tar = k/(n-1);
        cout<<arr[tar]<<endl;
       } 
    }
    return 0;
}