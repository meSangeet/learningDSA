//----------------------- Directives -----------------------/
#include <bits/stdc++.h>

//----------------------- Namespaces -----------------------/
using namespace std;

//-------------------- Type Definitions --------------------/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//------------------------- Macros -------------------------/
#define pub push_back
#define pob pop_back
#define mp make_pair
#define vi vector<ll>
#define vd vector<ld>
#define ss second
#define ff first
#define endl '\n'
#define rep(x,start,end) for(ll x = start; x < end; x++)
#define rrep(x,start,end) for(ll x = start; x >= end; x--)
#define read(x) rep(i, 0, x.size()) cin >> x[i]
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define coe(x) ll odd = 0, even = 0; rep(i, 0, x.size()) {if(x[i] % 2 == 0) even++; else odd++;}
#define c01(x) ll zero = 0, one = 0; rep(i, 0, x.size()) {if(x[i] == 0) zero++; else one++;}
#define p(x) cout << x << endl
#define p2(arr) rep(i, 0, arr.size()) cout << arr[i] << " "; cout << endl

//-------------------------- Maths -------------------------/
const int MOD = 1000000007;
template <typename T> inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;}
template <typename T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
template <typename T> inline bool isPrime(T n){for (T i=2;i*i<=n;i++) if(n%i==0) return false; return true;}
template <typename T> inline T Power_MOD(T a,T b){T res=1;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
template <typename T> inline T Power(T a,T b){long long res=1;while(b>0){if(b&1){res=res*a;}a*=a;b>>=1;}return res;}

//-------------------------- Debug -------------------------/
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

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue<T> pq){cerr<<"[ ";while(!pq.empty()){_print(pq.top());pq.pop();cerr<<" ";}cerr<<"]";}
template <class T> void _print(queue<T> q){cerr<<"[ ";while(!q.empty()){_print(q.front());q.pop();cerr<<" ";}cerr<<"]";}
template <class T> void _print(stack<T> stk){cerr<<"[ ";while(!stk.empty()){_print(stk.top());stk.pop();cerr<<" ";}cerr<<"]";}

//------------------------- Snippets -----------------------/
// Prime Factorization - get factors of a number using sieve
// sieve - checks weather a number is prime or not
// power - calc the a power b and also mod it
// Segment Tree - range based queries
// DSU - Disjoint set Union , gets number of components
// maxSubarray - get largest subarray of positive number
// string_hasing - get the string hash value and match 2 string (rabin karp)

//-------------------------- SOLVE -------------------------/
void solve() 
{
    cout<<1;
    ll n; cin>>n;
    vector<ll> a,b;
    for(ll i = 1; i<=(n-1); i++)
    {
        ll p; cin>>p;
        a.push_back(p);
    }
    ll indi = -1;
    b = a;
    cout<<1;
    vector<bool> present(n+2, false);
    for(ll i = 1; i<(n-1); i++)
    {
        a[i] -= b[i-1];
        if(present[a[i]] == true)
        {
            indi = a[i];
        }
        cout<<a[i]<<" ";
        if(a[i] < n+1 && a[i] >= 0)
        present[a[i]] = true;
    }
    cout<<endl<<"felo";
    cout<<endl;
    for(int i = 0; i<n+1; i++)
    {
        cout<<present[i]<<" "; 
    }
    cout<<endl;
    for(int i = 0; i<n-1; i++)
    {
        cout<<a[i]<<" "; 
    }
    ll p = -1, q = -1;
    for(ll i = 1; i<=n; i++)
    {
        if(present[i] == false)
        {
            if(p == -1)
            {
                p = a[i];
            }else{
                q = a[i];
            }
        }
    }
    if(present[n+1]) indi = n+1;
    if((p+q) == indi)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    /*
    bool flag = true, already = false;
    ll num, ind;

    sort(a.begin(), a.end());

    unordered_map<ll,ll> count;
    ll prev = -1;
    ll index = 0;
    count[a[0]]++;
    for(ll i = 1; i<(n-1); i++)
    {
        count[a[i]]++;
        if((a[i]) == (a[i-1] + 2)) index = i;
        if(count[a[i]] > 2)
        {
            cout<<"NO"<<endl;
            return;
        }

        if(count[a[i]] == 2)
        {
            if(already)
            {
                cout<<"NO"<<endl;
            }
            if(i > 0) prev = a[i];
            already = true;
            flag = false;
            num = a[i];
            ind = i;
        }
    }

    if(flag)
    {
        cout<<"NO"<<endl;
        return;
    }else{
        if((prev + 1) == num)
        {

        }

    }
    */
}

//--------------------------- MAIN -------------------------/
int main() {
    int t; 
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
