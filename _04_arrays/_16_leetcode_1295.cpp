#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            string str = to_string(nums[i]);
            if(str.length()%2 == 0) count++;
        }
        return count;
    }
};

int main()
{
    
    return 0;
}