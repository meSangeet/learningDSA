#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    
}

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> temp(nums);
        for(int i = 0; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i = 0; i<temp.size(); i++) cout<<temp[i]<<" ";
        stack<int> s;
        int n = nums.size();
        int l = temp.size()-1;
        vector<int> numss(n);
        for(int i = l; i >= 0; i--)
        {
            while(s.size() && s.top()<=temp[i])
            {
                s.pop();
            }

            if(!s.size())
            {
                s.push(temp[i]);
                cout<<i<<" "<<-1<<endl;
                if(i < n)
                numss[i] = -1;
            }else{
                int tep = s.top();
                cout<<i<<" "<<tep<<endl;
                s.push(temp[i]);
                if(i < n)
                numss[i] = tep;
            }
        }
        return numss;
    }
};


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}