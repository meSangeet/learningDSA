#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
ll n,k,x; cin>>n>>k>>x;
vector<ll> A(n+1,0);
for(int i = 1; i<=n; i++) cin>>A[i];
auto it = A.begin();
it++;
sort(it, A.end());
it = A.begin();
it++;
reverse(it, A.end());
vector<ll> ps(n+1,0);
ll curr = 0;
for(int i = 1; i<=n; i++)
{
curr += A[i];
ps[i] = curr;
}

ll ans = INT_MIN;
for(int i = 0; i<=k; i++)
{
ll ind = min(i + x, n);
ans = max(ans, curr - 2*ps[ind] + ps[i]);
}

cout<<ans<<"\n";
}

int main()
{
int t; cin>>t;
while(t--) solve();
return 0;
}