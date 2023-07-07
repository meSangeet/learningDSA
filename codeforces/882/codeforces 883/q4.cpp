#include <bits/stdc++.h>
using namespace std;


//macros
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
#define fr(n) for(ll iii = 0; iii<n; iii++)


//methods
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
        ll n, d, h;
        cin>>n>>d>>h;
        vector<ll> y(n+1);
        for(ll i = 1; i<=n; i++) cin>>y[i];
        double ch = h;
        double maxd = 0.0;
        for(int i = 1; i<=n; i++){
            double diff = (double)(y[i] - y[i-1])/double(d);
            ch+=diff;
            if(ch < 0.0){
                ch = 0.0;
                maxd = max(maxd, ch);
            }
        }
        double fh = maxd * (double)d;
        cout<<fh<<endl;
    }
}


//main function
int main()
{
    solve();
    return 0;
}