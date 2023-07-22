#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long double lld;

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
#define rv(n,v) fr(n){ll pppp; cin>>pppp; v.pub(pppp);}
#define take(a) ll a; cin>>a;

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

//debug
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template<class T> void _print(vector<T> v1)
{
    cerr << "[ ";
    for(T i:v1){
        _print(i);
        cerr<<" ";
    }
    cerr<<" ]";
}

template<class T> void _print(set<T> v1)
{
    cerr << "[ ";
    for(T i:v1){
        _print(i);
        cerr<<" ";
    }
    cerr<<" ]";
}


template<class T, class M> void _print(pair<T,M> p)
{
    cerr << "{ " << p.first <<" "<<p.second<<" }";
}

template<class T, class M> void _print(map<T,M> p)
{
    for(auto x : p)
    cerr << "{ " << x.first <<" "<<x.second<<" }"<<endl;
}

template<class T, class M> void _print(unordered_map<T,M> p)
{
    for(auto x : p)
    cerr << "{ " << x.first <<" "<<x.second<<" }"<<endl;
}


//solve for multiple test cases
void solve()
{
    int t; cin>>t;
    while(t--)
    {
        ll n, k; cin>>n>>k;
        vi dif;
        rv(n,dif);
        ll ans = 0;
        sort(dif.begin(), dif.end());
        for(ll i = 0; i<n;)
        {
            ll j = i+1;
            while(j < n)
            {
                if(dif[j] - dif[j-1] > k)
                {
                    break;
                }
                j++;
            }
            ans = max(ans, j-i);
            i = j;
        }
        cout<<(n - ans)<<"\n";
    }
}

//main function
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr); // to print debug into error.txt file
    #endif
    solve();
    return 0;
}