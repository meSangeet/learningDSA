class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int jmp = nums[i];
            int cur = dp[i];
            for(int k = i+1; k <= i + jmp and k < n; k++){
                dp[k] = min(dp[k], cur+1);
                // cout<<dp[k]<<" ";
            }
            // cout<<endl;
        }      
        return dp[n-1];
    }
};
