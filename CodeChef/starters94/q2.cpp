#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
#define pb push_back

ll mult(ll a, ll b, ll p = mod)
{
    return ((a % p) * (b % p)) % p;
}
ll add(ll a, ll b, ll p = mod)
{
    return ((a % p) + (b % p)) % p;
}
ll neg(ll a, ll p = mod)
{
    return (p - (a % p)) % p;
}
ll sub(ll a, ll b, ll p = mod)
{
    return add(a, neg(b));
}
ll fpow(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1ll)
            res = (res * x) % mod;
        y = y >> 1ll;
        x = (x * x) % mod;
    }
    return res;
}
ll inv(ll a, ll p = mod) { return fpow(a, p - 2); }

void solve()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> om;
        vector<int> addy;
        int oms = 0;
        int omsc = 0;
        int ads = 0;
        int adsc = 0;
        for(int i = 0; i<n; i++)
        {

            int p; cin>>p;
            om.pb(p);
            if(p != 0)
            {
                omsc++;
                if(omsc > oms) oms = omsc;
            }else{
                omsc = 0;
            }
        }
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            addy.pb(p);
            if(p != 0)
            {
                adsc++;
                if(adsc > ads) ads = adsc;
            }else{
                adsc = 0;
            }
        }
        if(oms > ads) cout<<"Om"<<endl;
        else if(oms == ads) cout<<"Draw"<<endl;
        else cout<<"Addy"<<endl;
    }
}
int main()
{
    solve();
    return 0;
}