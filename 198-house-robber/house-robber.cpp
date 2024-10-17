class Solution {
public:
//Dynamic programming coding practice

int fun(vector<int> &nums, int i, vector<int> &dp){
    if(i < 0){
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int take = fun(nums, i-2, dp) + nums[i];
    
    int notTake = fun(nums, i-1, dp);
    
    return dp[i] = max(take, notTake);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    
    //f(i) = answer till ith index so we need to find f(n-1)
    
    //base case
    vector<int> dp(n,-1);
    return fun(nums, n-1, dp);
}
};