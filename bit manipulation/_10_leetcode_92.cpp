#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> big;
    int n = nums.size();
    for (int i = 0; i < ((1 << n)); i++)
    {
        vector<int> small;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)))
            {
                small.push_back(nums[j]);
            }
        }
        big.push_back(small);
    }

    return big;
}

int main()
{

    return 0;
}