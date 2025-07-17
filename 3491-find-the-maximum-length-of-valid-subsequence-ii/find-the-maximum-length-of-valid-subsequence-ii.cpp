class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (k, 0)); //dp[i][k] -> maximum length of such subsequence ending
        //at the ith index with the remainder k
        int ans = 2;
        for(int i = 1; i<n; i++){
            int num1 = nums[i];
            for(int j = i-1; j >= 0; j--){
                int num2 = nums[j];
                int comb = num1 + num2;
                int rem = comb%k;
                if(dp[j][rem] == 0) dp[i][rem] = max(dp[i][rem],2);
                else
                dp[i][rem] = max(dp[i][rem], 1 + dp[j][rem]);
                ans = max(ans, dp[i][rem]);
            }
        }

        return ans;
    }
};