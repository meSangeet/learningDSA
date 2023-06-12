/*
removing the last set bit means

11011010 -> 11011000
*/

#include <bits/stdc++.h>
using namespace std;
int solution(int n)
{
    int ans; int mask = 1, i = 0;
    while(true)
    {
        mask = 1;
        mask = mask << i;
        if((n&mask) == 0)
        {
            i++;
            continue;
        }else{
            int mask2 = ~mask;
            ans = n&mask2;
            return ans;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << endl
         << solution(n);

    return 0;
}