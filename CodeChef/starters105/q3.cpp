#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int p,q; cin>>p>>q;
    vector<int> v(n);
    for(int i = 0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    long long ans = v[n-1] - v[0];
    vector<int> pos;
    for(int i = 1; i<n-1; i++)
    {
        pos.push_back(abs(v[i]));
    }
    sort(pos.begin(), pos.end());
    int i = pos.size()-1;
    int temp = (p+q);
    while(i >= 0 && temp--)
    {
        ans += pos[i--];
    }
    cout<<ans<<endl;
}
int main() {
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}