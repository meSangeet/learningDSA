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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            arr.pb(p);
            if (p % 2 == 0)
                even++;
            else
                odd++;
        }
        ll sumo = 0;
        ll count = 0;
        ll oddCount = 0;
        if (odd == 0)
        {
            sumo += fpow(2, even);
            cout << (sumo - 1) << endl;
        }
        else
        {
            sumo += fpow(2, even);
            cout << sumo << endl;
        }
        /*
        if(odd > 1){
            if(odd%2 == 0){
                for(int i = 2; i<=odd; i = i+2){
                    ll mul = 1;
                    for(int j = odd; j > (odd - i); j = j-2){
                        mul = (mul*j)%mod;
                    }
                    oddCount = (oddCount + mul)%mod;
                }
                sumo = (sumo+oddCount)%mod;
            }else{
                for(int i = 2; i<odd; i = i+2){
                    ll mul = 1;
                    for(int j = odd; j > (odd - i); j = j-2){
                        mul = (mul*j)%mod;
                    }
                    oddCount = (oddCount + mul)%mod;
                }
                sumo = (sumo+oddCount)%mod;
            }
            cout<<sumo<<endl;
        }*/
    }
    return 0;
}