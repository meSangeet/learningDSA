#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans (n,-1);
        int s = k, e = n-k-1;
        long long int avgi = 0, ws = 2*k;
        for(int i = 0; i<=ws && i<n; i++)
        {
            avgi += nums[i];
        }
        cout<<avgi<<" ";
        if(s<n && s<=e) ans[s] = avgi/(ws+1);
        for(int i = s+1; i<=e && i<n; i++)
        {
            avgi -= nums[i-k-1];
            avgi += nums[i+k];
            cout<<avgi<<" ";
            ans[i] = avgi/(ws+1);
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}