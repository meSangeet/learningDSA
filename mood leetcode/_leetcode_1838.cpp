#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

int maxFrequency(vector<int> &nums, int k)
{
    
    sort(nums.begin(), nums.end());
    int streak = 1;
    int count = 1;
    int ind = nums[nums.size()-1];
    int prev = nums[0];
    if (nums.size() == 1)
        return 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == prev)
        {
            count++;
            if (count > streak)
            {
                streak = count;
                ind = nums[i];
            }
        }
        else
        {
            count = 1;
            prev = nums[i];
        }
    }

    int i = 0;
    while (nums[i] != ind)
        i++;
    int st = i;
    int freq = 0;
    while (nums[i] == ind && i<nums.size())
    {
        freq++;
        i++;
    }

    if (st == 0)
        return freq;

    st--;
    while (st >= 0 && k > 0)
    {
        if ((ind - nums[st]) <= k)
        {
            freq++;
        }    
        int diff = ind - nums[st];
        k -= diff;
    }

    return freq;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        arr.push_back(p);
    }

    cout << "enter the value of k - ";
    int k;
    cin >> k;
    int ans = maxFrequency(arr, k);
    cout<<endl<<ans;
    return 0;
}