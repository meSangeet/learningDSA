#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int s = 0, l = (n - 1), rs = 0;
    while (rs < m)
    {
        cout << 23;
        if (matrix[rs][0] == target)
            return true;
        else if (matrix[rs][n - 1] < target)
            rs++;
        else
            goto x;
    }
x:
    if (rs >= m)
        return false;
    int mid = s + (l - s) / 2;
    while (s <= l)
    {
        if (matrix[rs][mid] == target)
            return true;
        else if (matrix[rs][mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
        mid = s + (l - s) / 2;
    }

    return 0;
}

int main()
{
    vector<vector<int>> vec;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int p;
            cin >> p;
            temp.push_back(p);
        }
        vec.push_back(temp);
    }
    int target;
    cin >> target;
    cout << endl
         << searchMatrix(vec, target);
    return 0;
}