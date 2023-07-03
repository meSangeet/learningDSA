#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int miin = INT_MAX;
        unordered_map<int,int> m;
        for(int i = 0; i<nums1.size(); i++)
        {
            m[nums1[i]] = 1;
        }
        for(int i = 0; i<nums2.size(); i++)
        {
            if(nums2[i] < miin)
            {
                if(m[nums2[i]]) miin = nums2[i];
            }
        }
        if(miin == INT_MAX) return -1;
        return miin;
    }
};

int main()
{
    
    return 0;
}