class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int n = nums.size();
        int sec = -1;
        sec = nums.back();
        int ans = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < sec){
                ans = max(ans, sec - nums[i]);
            }else{
                sec = nums[i];
            }
        }

        return ans;
    }
};