#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "Ada\n";
        return;
    }

    ll maxi = *max_element(a.begin(), a.end());
    ll mini = *min_element(a.begin(), a.end());

    while (mini != maxi)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] % 10 == 0 && (a[i] != maxi))
            {
                cout << "Eve"
                     << "\n";
                return;
            }
            ll temp = a[i] + (a[i]%10);
            if ((a[i] != a[n-1]))
            {
                a[i] = temp;
            }
        }

    maxi = *max_element(a.begin(), a.end());
    mini = *min_element(a.begin(), a.end());
    }
    
    if (a[0] == a[n - 1])
    {
        cout << "Ada"
             << "\n";
    }
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}