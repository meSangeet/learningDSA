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

    }
}
string lasttwo(string s)
{
    string ans;
    
    ans.pb(s[s.size()-2]);
    ans.pb(s[s.size()-1]);
    return ans;

}
int main()
{
    int n; cin>>n;
    vector<string> programs;
    for(int i = 0; i<n; i++)
    {
        string s;  cin>>s;
        programs.pb(s);
    }

    unordered_map<string,int> m;

    for(int i = n-1; i>=0; i--)
    {
        if(m[programs[i]] == 0)
        {
            cout<<lasttwo(programs[i]);
            m[programs[i]] = 1;
        }
    }
    return 0;
}