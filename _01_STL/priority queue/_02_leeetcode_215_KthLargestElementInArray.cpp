#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());

    for (int i = 1; i < k; i++)
    {
        pq.pop();
    }

    return pq.top();
}

int main()
{

    return 0;
}