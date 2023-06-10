#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
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
}
ll inv(ll a, ll p = mod) { return fpow(a, p - 2); }


int bigExpInt(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a)% mod;
        }
        a = (a * 1ll * a)%mod;
        b >>= 1;
    }
    return ans;  
}
int main()
{
    int a ,b; cin>>a>>b;
    cout<<bigExpInt(a,b);
    return 0;
}