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
        ll n, k;
        cin >> n >> k;
        vector<ll> planks(n + 1);
        vector<vector<ll>> distances(n + 1, vector<ll>());
        unordered_map<int,int> ind;

        for (ll i = 1; i <= n; i++)
        {
            cin >> planks[i];
        }

        for (ll i = 1; i <= n; i++)
        {
            distances[planks[i]].push_back(i - ind[planks[i]]);
            distances[planks[i]].back()--;
            ind[planks[i]] = i;
        }

        ll minimum = LONG_LONG_MAX;
        for (ll i = 1; i <= k; i++)
        {
            distances[i].push_back(n - ind[i]);
            sort(distances[i].begin(), distances[i].end(), greater<int> ());
            ll res = distances[i][0] >> 1;

            if (distances[i].size() >= 2)
            {
                res = max(res, distances[i][1]);
            }

            minimum = min(minimum, res);
        }

        cout << minimum << endl;
    }
}


//main function
int main()
{
    solve();
    return 0;
}