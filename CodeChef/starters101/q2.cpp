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

// function to get the index of s2 in s1
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

void solve() 
{
	ll n,m; cin>>n>>m;
	string s; cin>>s;
	string k; cin>>k;

	int ans = INT_MAX;

	int l = 0, r = m-1;

	while(r <= n-1)
	{
		int ind = 0;
		int temp = l;
		int tempans = 0;
		while(temp <= r)
		{
			debug(temp)
			debug(s[temp])
			int dif1 = abs(s[temp] - k[ind]);
			int dif2 = abs(10 - dif1);
			tempans += min(dif1, dif2);
			temp++;
			ind++;
			debug(tempans)
		}
		ans = min(tempans, ans);

		if(ans == 0)
		{
			cout<<0<<endl;
			return;
		}
		r++;
		l++;
	}

	cout<<ans<<endl;
	return;

}

//--------------------------- MAIN -------------------------/
int main() {

    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr); // to print debug into error.txt file
    #endif

    ios_base::sync_with_stdio(false); // to make input output faster
    cin.tie(NULL);

    int t = 1; 
    cin>>t;
    while(t--)
    {
    	solve();
    }
    return 0;
}
