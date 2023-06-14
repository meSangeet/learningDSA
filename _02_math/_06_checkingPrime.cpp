#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

bool isPrime(ll n)
{
    int till = sqrt(n);
    for(int i = 2; i<=till; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        if(isPrime(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}