#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> A, int k, int sum)
{
    int size = A.size();
    sort(A.begin(), A.end());
    int ind = size - k;
    int minus = A[ind];
    if (minus == 0)
        return sum;
    sum += minus;
    int j = k;
    for (int i = (size - 1); j > 0; i--)
    {
        A[i] -= minus;
        j--;
    }
    return solution(A, k, sum);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            A.push_back(p);
            sum += p;
        }
        if (sum < k)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << solution(A, k, 0);
        }
    }
    return 0;
}
