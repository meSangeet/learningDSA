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

bool isVowel(char a)
{
    unordered_map<char, bool> m;
    m['a'] = true;
    m['e'] = true;
    m['i'] = true;
    m['o'] = true;
    m['u'] = true;

    if (m[a] == true)
        return true;

    return false;
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count = 0;
        vector<int> gap; //consonants between two vowels
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                count++;
                gap.push_back(p);
                p = 0;
            }else{
                p++;
            }
            
        }

        ll ans = 1;
        /*
        count = no of vowels
        k = no of vowels in each slice
        each = no of slice
        */
        int st = k; // gap array starting index
        int l = gap.size() - k; // gap array ending index
        for(int i = st; i<=l; i = i+k)
        {
            ans = mult(ans, gap[i]+1, mod);
        }
        cout<<ans<<endl;
    }
}
int main()
{
    solve();
    return 0;
}