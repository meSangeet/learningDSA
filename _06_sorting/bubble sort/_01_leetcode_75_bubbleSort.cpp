#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = 0; j<nums.size() - i - 1; j++)
            {
                if(nums[j+1] < nums[j])
                {
                    swap(nums[j+1], nums[j]);
                }
            }
        }
    }
};

int main()
{
    
    
    
    return 0;
}
