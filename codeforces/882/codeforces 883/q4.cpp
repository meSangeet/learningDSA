#include <bits/stdc++.h>
using namespace std;


//macros
#define mod 1000000007
#define ll long long
#define ld long double
#define lld long long double
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
        ld n,d,h; cin>>n>>d>>h;
        vector<ld> arr;
        
        for(ll i = 0; i<n; i++)
        {
            ld p; cin>>p;
            arr.pub(p);
        }

        sort(arr.begin(), arr.end());
        long double area = (0.5)*(long double)(d)*(long double)(h);
        long double secArea = area/pow(2,h);
        long double sum = 0;
        ll prev = LONG_LONG_MAX;
        for(ll i = n-1; i>=0; i--)
        {
            ll high = arr[i] + h;
            if(high < prev) {sum+=area;}
            else{
                ll levels = h - prev + arr[i];
                long double ss = d + ((long double)(levels)/h)*d;
                long double tba = (0.5)*(long double)(h - levels)*ss;
               sum += tba;
            }

            prev = arr[i];
        }
        cout<<fixed<<setprecision(6)<<sum<<endl;
    }
}


//main function
int main()
{
    solve();
    return 0;
}