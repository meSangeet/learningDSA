#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = 0; j<nums[i].size(); j++)
            {
                m[nums[i][j]] += 1;
            }
        }
        for(auto x:m)
        {
            if(x.second == nums.size()) ans.push_back(x.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    
    return 0;
}