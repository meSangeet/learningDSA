#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] += 1;
    }
    vector<pair<int, int>> v;
    for (auto x : m)
    {
        pair<int, int> p = {x.second, x.first};
        v.push_back(p);
    }

    priority_queue<pair<int, int>> pq(v.begin(), v.end());

    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main()
{

    return 0;
}