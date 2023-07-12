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
        
    unordered_map<int,int> m;
    ll n; cin>>n;
    vector<ll> a;
    ll maax = INT_MIN;
    for(ll i = 0; i<n; i++)
    {
        ll p; cin>>p;
        a.pub(p);
        m[p]++;
        if(m[p] > maax) maax = m[p];
    }
    vector<ll> d;
    for(ll i = 0; i<n; i++)
    {
        ll p; cin>>p;
        d.pub(p);
        m[p]++;
        if(m[p] > maax) maax = m[p];
    }
    cout<<maax<<endl;
    }
}


//main function
int main()
{
    solve();
    return 0;
}