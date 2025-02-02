class Solution {
public:
    bool check(vector<int>& nums) {
        int prev = INT_MIN;
        int count = 1;
        int mini = INT_MAX; int i;
        for(i = 0; i<nums.size(); i++)
        {
           if(nums[i] >= prev) 
           {
               mini = min(mini, nums[i]);
               prev = nums[i];
           }else{
               goto x;
           }
        }

        x:
        prev = INT_MIN;
        while(i<nums.size())
        {
            if(nums[i] > mini){ return false; }
            else if(prev>nums[i]) return false;
            prev = nums[i];
            i++;
        }

        return true;
    }
};