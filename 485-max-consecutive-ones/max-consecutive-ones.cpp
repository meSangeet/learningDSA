class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                cur++;
                ans = max(cur, ans);
            }else{
                cur = 0;
            }
        }

        return ans;
    }
};