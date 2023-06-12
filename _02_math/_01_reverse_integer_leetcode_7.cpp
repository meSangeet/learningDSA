#include <bits/stdc++.h>
using namespace std;

long long int reverse(long long int x)
{
    if ((x < -1 * pow(2, 31)) || (x >= pow(2, 31)))
        return 0;
    if (x < 0)
    {
        long long int mulf = 10;
        long long int temp = 0;
        x *= -1;
        while (x != 0)
        {
            int curr = x % 10;
            temp *= mulf;
            temp += curr;
            x /= 10;
        }
        temp *= -1;
        if ((temp < -1 * pow(2, 31)) || (temp >= pow(2, 31)))
            return 0;
        return temp;
    }
    long long int mulf = 10;
    long long int temp = 0;
    while (x != 0)
    {
        int curr = x % 10;
        temp *= mulf;
        temp += curr;
        x /= 10;
    }
    if ((temp < -1 * pow(2, 31)) || (temp >= pow(2, 31)))
        return 0;
    return temp;
}
int main()
{

    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        cout << endl
             << reverse(n);
    }
    return 0;
}