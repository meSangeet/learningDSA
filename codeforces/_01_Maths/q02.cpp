#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pub push_back
#define pob pop_back
#define pof pop_front
#define puf push_front
#define mp make_pair
#define vi vector<ll>
#define vp vector<pair<ll,ll>>
#define vii vector<vi>
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
        vi a;
        ll p; cin>>p;
        a.pub(p);
        ll miin = a[0];
        for(ll i = 1; i<n; i++)
        {
            cin>>p;
            a.pub(p);
            miin &= p;
        }
        if(miin > 0) cout<<1<<endl;
        else{
            ll groups = 0;
            ll curr = a[0];
            for(ll i = 1; i<n; i++)
            {
                if(curr == 0){
                    groups++;
                    curr = a[i];
                }else{
                    curr &= a[i];
                }
            }

            if(curr == 0) cout<<groups+1<<endl;
            else cout<<groups<<endl;
        }
    }
}
int main()
{
    solve();
    return 0;
}