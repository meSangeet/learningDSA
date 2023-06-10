#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

int bigExpRecur(int a, int b)
{
    if(b == 0) return 1;
    if(b%2 == 0)
    {
        return bigExpRecur(a,b/2)*bigExpRecur(a,b/2);
    }else{
        return a*bigExpRecur(a,b/2)*bigExpRecur(a,b/2);
    }
}

int main()
{
    int a; int b; cin>>a>>b;
    cout<<bigExpRecur(a,b);
    return 0;
}