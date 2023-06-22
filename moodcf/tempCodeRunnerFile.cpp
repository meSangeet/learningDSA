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
        for(ll i = 0; i<n; i++)
        {
            ll p; cin>>p;
            a.pb(p);
        }
        ll m, sm;
        if(a[0] > a[1])
        {
            m = a[0];
            sm = a[1];
        }else{
            m = a[1];
            sm = a[0];
        }
        for(ll i = 3; i<n; i++)
        {
            if(a[i] > m)
            {
                sm = m;
                m = a[i];
            }else{
                if(a[i] > sm)
                {
                    sm = a[i];
                }
            }
        }


        cout<<(m*sm)<<endl;
    }
}
int main()
{
    solve();
    return 0;
}