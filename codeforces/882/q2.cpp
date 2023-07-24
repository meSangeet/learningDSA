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
        ll n; cin>>n;
        vector<int> a;
        ll miin = INT_MAX;
        for(ll i =0;i<n; i++)
        {
            ll p; cin>>p;
            a.pb(p);
            if(a[i] < miin)miin = a[i];
        }

        ll groups = 0;
        ll mm = 1;

        while(mm < 1e9)
        {
            mm *= 2;
        }
        mm = -1;
        ll ms = mm;
        for(ll i = 0; i<n; i++)
        {
            ms &= a[i];
        }
        ll cur = ms;
        for(ll i = 0; i<n; i++)
        {
            cur &= a[i];
            if(cur == 0)
            {
                groups += 1;
                cur = ms;
            }
        
        }
        groups += ms>0;
        cout<<groups<<endl;
    }
}
int main()
{
    solve();
    return 0;
}