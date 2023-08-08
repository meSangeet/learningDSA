#include <bits/stdc++.h>
using namespace std;

void solve(int amount, int ind, vector<int>& coins, int &sum)
{
    if(ind == coins.size()) return;
    if(amount < 0) return;
    if(amount == 0)
    {
        sum++;
    }

    solve(amount - coins[ind], ind, coins, sum);

    solve(amount, ind+1, coins, sum);
}
int change(int amount, vector<int> &coins)
{
    int sum = 0;
    solve(amount, 0, coins, sum);
    return sum;
}

int main()
{
    int amt;
    cin >> amt;
    int n;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        coins.push_back(p);
    }

    cout << endl
         << change(amt, coins);
}