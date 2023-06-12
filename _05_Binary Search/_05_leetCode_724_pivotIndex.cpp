#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix[nums.size()];
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum+=nums[i];
            prefix[i] = sum;
            cout<<prefix[i]<<" ";
        }
        cout<<endl;
        sum = 0;
        int ans = -1;

        for(int i = 0; i<nums.size(); i++)
        {
            int leftSum = 0, rightSum = 0;
            if(i > 0) leftSum = prefix[i-1];
            if(i < (n-1)) rightSum = (prefix[n-1] - prefix[i]);
            if(leftSum == rightSum)
            {
                return i;
            }
            cout<<leftSum<<" "<<rightSum<<endl;

        }

        return ans;
    }
};

int main()
{
    
    return 0;
}