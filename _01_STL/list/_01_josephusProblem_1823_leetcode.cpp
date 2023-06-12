#include <bits/stdc++.h>
using namespace std;

int findTheWinner(int n, int k)
{
    list<int> l;
    for (int i = 0; i < n; i++)
    {
        l.push_back(i + 1);
    }
    cout << " " << endl;
    for (int x : l)
    {
        cout << x << " ";
    }
    cout << " " << endl;
    auto it = l.begin();
    while (l.size() != 1)
    {
        for (int i = 1; i < k; i++)
        {
            it++;
            if (it == l.end())
            {
                it = l.begin();
            }
        }
        it = l.erase(it);
        cout << " " << endl;
        for (int x : l)
        {
            cout << x << " ";
        }
        cout << " " << endl;
        if (it == l.end())
        {
            it = l.begin();
        }
    }
    return *l.begin();
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findTheWinner(n, k);
    return 0;
}