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
    ll T; cin>>T;
    while(T--)
    {
        vector<vector<ll>> pos;
        ll n,m,h; cin>>n>>m>>h;

        vector<vector<ll>> T;
        for(ll i = 0; i<n; i++)
        {
            vector<ll> temp;
            for(ll j = 0; j<m; j++)
            {
                ll p; cin>>p;
                temp.pub(p);
            }
            sort(temp.begin(), temp.end());
            ll points = 0, penalty = 0, poop = 0,tim = h;
            for(ll j = 0; j<m; j++)
            {
                if(temp[j] <= tim){
                    points++;
                    penalty += temp[j];
                    tim -= temp[j];
                    poop += penalty;
                }
            }
            pos.pub({points, poop, i});
            T.pub(temp);
        }
        //counting for rudolph
        ll rank = 1;
        for(int i = 1; i<n; i++)
        {
            if(pos[i][0] > pos[0][0])
            {
                rank++;
            }
            if(pos[i][0] == pos[0][0])
            {
                if(pos[i][1] < pos[0][1])
                {
                    rank++;
                }
            }
        }
        cout<<rank<<endl;
    }
}


//main function
int main()
{
    solve();
    return 0;
}