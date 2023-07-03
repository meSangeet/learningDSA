#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i = 0; i<nums1.size(); i++)
        {
            m[nums1[i]] += 1;
        }

        vector<int> ans;
        for(int i = 0; i<nums2.size(); i++)
        {
            if(m[nums2[i]])
            {
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}