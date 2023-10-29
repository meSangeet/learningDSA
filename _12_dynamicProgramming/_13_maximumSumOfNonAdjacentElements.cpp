#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 2)
        {
            return *max_element(nums.begin(), nums.end());
        }
        int a = nums[n-1];
        int b = max(nums[n-1], nums[n-2]);
        for(int i = n-3; i>=0; i--)
        {
            int temp = max(b, a + nums[i]);
            a = b;
            b = temp;
        }

        return b;
    }
};

//main function
int main()
{

    return 0;
}