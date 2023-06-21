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
        int n,m,h;
        cin>>n>>m>>h;
        vector<int>cars;
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            cars.pb(p);
        }
        vector<int> outlets;
        for(int i = 0; i<m; i++)
        {
            int p; cin>>p;
            outlets.pb(p);
        }

        ll ans = 0;
        sort(cars.begin(), cars.end(), greater<int>());
        sort(outlets.begin(), outlets.end(), greater<int>());

        int mini = min(n,m);

        for(int i = 0; i<mini; i++)
        {
            long long int temp = h*outlets[i];
            if(temp > cars[i])
            {
                ans += cars[i];
            }else{
                ans += temp;
            }
        }
        cout<<ans<<endl;
    }
}
int main()
{
    solve();
    return 0;
}