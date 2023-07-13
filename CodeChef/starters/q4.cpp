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
        ll n; cin>>n;
        string s; cin>>s;
        if(s.length()%3 == 1)
        {
            cout<<"YES"<<endl;
        }else{
                bool f = false;
            if(s.length()%3 == 2)
            {
                for(ll i = 0; i<n; i = i+3)
                {
                    char temp = s[i];
                    ll j = i+1;
                    for(; j<n; j = j+3)
                    {
                        if(s[j] == temp)
                        {
                            f = true;
                        }
                    }
                }

            }else{
                for(ll i = 0; i<n; i = i+2)
                {

                    for(ll j = i+2; j<n; j = j+2)
                    {
                        if(s[j] == s[i])
                        f = true;
                    }
                }
            }
            if(f) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}


//main function
int main()
{
    solve();
    return 0;
}