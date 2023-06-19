#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++)
        {
            hash[nums[i]] += 1;
            if(hash[nums[i]] > (n/2)) return nums[i];
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}