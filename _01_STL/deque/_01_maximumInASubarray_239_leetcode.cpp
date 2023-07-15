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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int currIndex = k-1;
    vector<int>ans;
    deque<int> dq;
    for(int i = 0; i<k-1; i++)
    {
        insertt(dq, nums, i);
    }
    while(currIndex != nums.size())
    {
        insertt(dq, nums, currIndex);
        if(dq.front() > (currIndex - k ))
        {
            ans.push_back(nums[dq.front()]);
        }else{
            dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        currIndex++;
    }
    return ans;
}

int main()
{
    cout<<"enter the number of elements in your array - "; int n; cin>>n;
    vector<int> arr;
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        arr.push_back(p);
    }
    cout<<endl<<"enter the size of window - "; int k; cin>>k;
    vector<int> ans;
    cout<<endl<<"the final array is - ";
    ans = maxSlidingWindow(arr, k);
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}