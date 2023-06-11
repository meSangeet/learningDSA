#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

vector<vector<int>> threeSUM(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> remover;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int lo = i + 1, hi = (nums.size() - 1);

        while (lo < hi)
        {
            int sum = nums[lo] + nums[hi];
            int target = -1 * nums[i];
            if (sum == target)
            {
                vector<int> temp;
                temp = {nums[lo], -1 * target, nums[hi]};
                remover.insert(temp);
                while ((lo < hi) && (nums[lo] == nums[lo + 1]))
                {
                    lo++;
                }
                while ((lo < hi) && (nums[hi] == nums[hi - 1]))
                {
                    hi--;
                }
                lo++;
                hi--;
            }
            else if (sum > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
    }

    for (auto x : remover)
    {
        ans.push_back(x);
    }
    return ans;
}
int main()
{
    cout << "enter the number of elements in your array -> ";
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        arr.push_back(p);
    }
    vector<vector<int>> triplets = threeSUM(arr);
    for (int i = 0; i < triplets.size(); i++)
    {
        for (auto x : triplets[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}