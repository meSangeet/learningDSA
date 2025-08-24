class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int prev = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(i == 0){
                    continue;
                }else{
                    if(nums[i-1] == 0){
                        prev = 0;
                    }else{
                        prev = cur;
                    }
                }

                cur = 0;
            }else{
                cur++;
                ans = max(ans, cur+prev);
            }
        }

        return min(ans, n-1);
    }
};