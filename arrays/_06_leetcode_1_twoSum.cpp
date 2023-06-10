#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,bool> b;
        for(int i = 0; i<nums.size(); i++)
        {
            b[nums[i]] = true;
            m[nums[i]] = i;
        }
    vector<int> ans;
        for(int i = 0 ; i<nums.size(); i++)
        {
            int t = target - nums[i];
            if(b[t])
            {
                if(m[t] == i) continue;
                ans.push_back(i);
                ans.push_back(m[t]);
                return ans;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}