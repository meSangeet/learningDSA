#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

int solution(vector<vector<int>> matrix)
{
    int n = matrix.size() / 2;
    for (int i = 0; i < matrix.size(); i++)
    {
        ll sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += matrix[i][j];
        }
        for (int j = n; j < 2 * n; j++)
        {
            sum2 += matrix[i][j];
        }
        if (sum2 > sum1)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    ll sum = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        ll sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            sum1 += matrix[j][i];
        }
        for (int j = n; j < 2 * n; j++)
        {
            sum2 += matrix[j][i];
        }
        sum += max(sum1, sum2);
    }
    return sum;
}
int main()
{

    return 0;
}