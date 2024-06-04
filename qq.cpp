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
#define py cout << "Yes" << endl
#define pn cout << "No" << endl
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

// ... (other functions)

void solve() {
    ll n; cin>>n;
    if(n == 1 || n == 3 || n == 5 || n == 7)
    {
        cout<<1<<endl;
        return;
    }
    if(n < 4)
    {
        cout<<0<<endl;
        return;
    }
    ll i = 1;
    bool flag = false;
    if(n % 2 != 0)
    {
        if(n < 9)
        {
            cout<<0<<endl;
            return;
        }
        flag = true;
    }

    ll j = n-1;
    ll count = 0;
    if(flag)
    {
        i = 3;
        j = n-4;
    }


    while(i < j)
    {
        // cout<<i<<" "<<j<<endl;
        count++;
        i += 2;
        j -= i;
        i += 2;
        j -= i;
    }
    if(flag) count++;
    cout<<count<<"\n";
}

int main() {
    FAST;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}