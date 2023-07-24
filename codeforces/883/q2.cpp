#include <bits/stdc++.h>
using namespace std;

// macros
#define mod 1000000007
#define ll long long
#define ld long double
#define pub push_back
#define pob pop_back
#define pof pop_front
#define puf push_front
#define mp make_pair
#define vi vector<ll>
#define vp vector<pair<ll, ll>>
#define vii vector<vi>
#define pie 3.1415926535898
#define pb push_back
#define fr(n) for (ll iii = 0; iii < n; iii++)

// methods
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

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool flag = true;
        vector<vector<char>> arr(3, vector<char>(3, '.'));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char ap;
                cin >> ap;
                arr[i][j] = ap;
            }
        }
        if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][1] != '.')
        {
            cout<<arr[0][0]<<endl;
        }
        else if
        (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][1] != '.') cout<<arr[1][1]<<endl;
        else if
        (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][1] != '.')
        cout<<arr[2][1]<<endl;
        else if
        (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != '.') cout<<arr[0][0]<<endl;
        else if
        (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != '.') cout<<arr[0][1]<<endl;
        else if
        (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != '.') cout<<arr[0][2]<<endl;
        else if
        (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.') cout<<arr[0][0]<<endl;
        else if
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '.') cout<<arr[0][2]<<endl;
        else cout<<"DRAW"<<endl;
    }
}

// main function
int main()
{
    solve();
    return 0;
}