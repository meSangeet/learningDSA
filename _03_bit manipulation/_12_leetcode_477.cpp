// TLE Solution  35/46 test cases passed

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

class Solution {
public:
    int hammingBits(int a, int b)
    {
        int count = 0, n = 1;
        while((a != 0) || (b!=0))
        {   
            int comp1 = (a&n);
            int comp2 = (b&n);

            if(comp1 != comp2)
            {
                count++;
            }
            a = a>>1;
            b = b>>1;
        }
        return count;
    }
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return 0;
        }
        int sum = 0;
        for(int i = 0; i<nums.size()-1; i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                sum += hammingBits(nums[i], nums[j]);
            }
        }
        return sum;
    }
};

int main()
{
    
    
    
    return 0;
}