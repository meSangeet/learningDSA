#include <bits/stdc++.h>
using namespace std;

void insertt(deque<int> &dq, vector<int> &nums, int x)
{
    if(dq.size() == 0)
    {
        dq.push_back(x);
        return;
    }
    if(nums[x] >= nums[dq.front()])
    {
        dq.clear();
        dq.push_back(x);
        return;
    }
    while(nums[dq.back()] <= nums[x])
    {
        dq.pop_back();
    }
    dq.push_back(x);
    return;
}

vector<int> printt(vector<int> dq)
{
    vector<int> ans = {5,4,3,3,1};
    return ans;
}
int main()
{
    
    vector<int> nums = {4,3,2,1,2,3,4};
    vector<int> ans;
    ans = printt(nums);
    for(int i = 0; i<5; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}