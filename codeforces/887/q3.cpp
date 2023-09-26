#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a(n);
int n, k;
bool checkmid(ll x)
{
    ll days = k;
    ll mux = n;
    while(days--)
    {
        while(mux > 0 && a[mux-1] > x) mux--;
        x -= mux;
    }

    if(x < 1)
    {
        return false;
    }

    return true;

}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (a[0] != 1)
    {
        cout << 1 << endl;
        return;
    }
    ll s = 1, e = (ll)n * k + 10;
    ll ans = 1;
    while (s <= e)
    {
        ll mid = s + (e - s) / 2;
        if (checkmid(mid))
        {
            e = mid;
            ans = e;
        }else{
            s = mid+1;
        }
    }

    cout<<ans<<endl;
}
// main function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}