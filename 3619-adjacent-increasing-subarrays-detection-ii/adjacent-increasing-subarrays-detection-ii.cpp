class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cur = 1;
        int prev = 0;
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                cur++;
                if(cur % 2 == 0){
                    ans = max(ans, cur/2); //as even can always be divided by 2
                }

                if(cur <= prev){
                    //cur and prev can be taken together
                    ans = max(ans, cur);
                }
            }else{
                //cur becomes previous
                prev = cur;
                cur = 1;
            }
        }
        return ans;
    }
};