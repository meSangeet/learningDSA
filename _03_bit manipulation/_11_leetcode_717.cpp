#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
        {
            return true;
        }
        int temp = 0;
        while(temp<length)
        {
            if(temp == (length-1))
            {
                return true;
            }
            if(nums[temp] == 1)
            {
                temp += 2;
            }else{
                temp++;
            }
        }
        return false;
    }
};

int main()
{
    
    
    
    return 0;
}