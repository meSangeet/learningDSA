#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
    
int main()
{
    int t; cin>>t; 
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> A;
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            A.push_back(p);
        }

        sort(A.begin(), A.end());

        int j = k;
        for(int i = 0; k>0; i++)
        {
            A[i] += 1;
            k--;
        }
        ll sum = 0;
        for(int i = 0; i<A.size(); i++)
        {
            for(int j = i; j<A.size(); j++)
            {
                sum += (A[i]*A[j])%mod;
                sum %= mod;
            }
        }

        cout<<sum<<endl;
    }
    
    
    return 0;
}