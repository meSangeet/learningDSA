#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
bool check(ll a, ll x)
{
    for (int i = 0; i < 32; i++)
    {
        if (!(1 & (x >> i)))
        {
            if (1 & (a >> i))
                return false;
        }
    }
    return true;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a;
        vector<ll> b;
        vector<ll> c;
        for (ll i = 0; i < n; i++)
        {
            ll p;
            cin >> p;
            a.push_back(p);
        }
        for (ll i = 0; i < n; i++)
        {
            ll p;
            cin >> p;
            b.push_back(p);
        }
        for (ll i = 0; i < n; i++)
        {
            ll p;
            cin >> p;
            c.push_back(p);
        }
        ll i = 0, j = 0, k = 0, curr = 0;
        if (curr == x)
            cout << "Yes" << endl;
        else
        {
            while (i < n)
            {
                if (!check(a[i], x))
                    goto m;
                curr = curr | a[i];
                i++;
            }
        m:
            while (j < n)
            {
                if (!check(b[j], x))
                    goto n;
                curr = curr | b[j];
                j++;
            }
        n:
            while (k < n)
            {
                if (!check(c[k], x))
                    goto o;
                curr = curr | c[k];
                k++;
            }
        o:

            if (curr == x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}