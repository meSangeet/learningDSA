#include <bits/stdc++.h>
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
#define vd vector<ld>
#define vb vector<bool>
#define pll pair<ll,ll>
#define maxint 2147483647
#define minint -2147483648
#define endl '\n'
#define rep(x,start,end) for(ll x = start; x < end; x++)
#define rrep(x,start,end) for(ll x = start; x >= end; x--)
#define read(x) rep(i, 0, x.size()) cin >> x[i]
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pyn(x) if(x) py; else pn
#define coe(x) ll odd = 0, even = 0; rep(i, 0, x.size()) {if(x[i] % 2 == 0) even++; else odd++;}
#define c01(x) ll zero = 0, one = 0; rep(i, 0, x.size()) {if(x[i] == 0) zero++; else one++;}
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define F first
#define S second
using namespace std;

ll mod1 = 1e9 + 7, mod2 = 998244353;

template<typename T> void p(T t, bool newln = true){
    cout << t;
    if(newln) cout << endl;
    else cout << " ";
}

template<typename T> void p(vector<T> t){
    rep(i, 0, sz(t)) p(t[i], false);
    cout << endl;
}

template<typename T, typename U> void p(pair<T, U> t){
    p(t.F, false);
    p(t.S);
}



void solve() {
    ll n, k; cin>>n>>k;
    vi a(n);
    read(a);
    ll ans = 0;
    for(int i = 0; i<n-1; i++)
    {
        ans += abs(a[i] - a[i+1]);
    }
    ll tomb = ans;
    for(int i = 1; i<n-1; i++)
    {
        ll ansi = ans;
        ansi -= abs(a[i-1] - a[i]);
        ansi -= abs(a[i] - a[i+1]);
        ll aa = ansi;

        ansi += abs(a[i-1] - 1);
        ansi += abs(1 - a[i+1]);
        aa += abs(a[i-1] - k);
        aa += abs(k - a[i+1]);

        tomb = max({tomb, ansi, aa});
    }
    if(n >= 2){
    ll ansi = ans;
    ansi -= abs(a[0] - a[1]);
    ansi += abs(1 - a[1]);

    tomb = max(tomb, ansi);

    ansi -= abs(1 - a[1]);
    ansi += abs(k - a[1]);

    tomb = max(tomb, ansi);

    ansi = ans;

    ansi -= abs(a[n-2] - a[n-1]);
    ansi += abs(a[n-2] - 1);
    tomb = max(tomb, ansi);
    ansi -= abs(a[n-2] - 1);
    ansi += abs(a[n-2]-k);
    tomb = max(tomb, ansi);
    }
    p(tomb);
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}