#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int divide(int dividend, int divisor)
{
    int ans = 0;
    bool flag = false;

    if (dividend < 0)
    {
        flag = true;
        dividend *= -1;
    }
    if (divisor < 0)
    {
        flag = true;
        divisor *= -1;
    }
    if ((divisor < 0) && (dividend < 0))
    {
        flag = false;
        dividend *= -1;
        divisor *= -1;
    }

    while (dividend >= divisor)
    {
        ans += 1;
        divisor = (divisor << 1);
    }

    if (flag)
        ans *= -1;
    return ans;
}

int main()
{
    cout<<divide(20,3);
    return 0;
}