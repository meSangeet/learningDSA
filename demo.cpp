#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> dist(n + 1);
        vector<int> pre(n + 1, 0);
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            pre[i] = 0;
            dist[i] = {};
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            dist[a[i]].push_back(i - pre[a[i]] - 1);
            pre[a[i]] = i;
        }

        int mn = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            dist[i].push_back(n - pre[i]);
            sort(dist[i].rbegin(), dist[i].rend());
            int res = dist[i][0] / 2;

            if (dist[i].size() >= 2)
            {
                res = max(res, dist[i][1]);
            }

            mn = min(mn, res);
        }

        cout << mn << endl;
    }

    return 0;
}