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
    vector<int> dp(n+2, 0);

    for(int i = 2; i<=n+1; i++){
        //case 1
        int c1 = nums[i-2] + dp[i-2]; 
        //case 2
        int c2 = dp[i-1];

        dp[i] = max(c1,c2);
    }

    return dp[n+1];
}
};