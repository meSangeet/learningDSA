class Solution {
public:
    int dp[220][100000] = {-1};
    int f(vector<int>& nums, int ind, int sum)
    {
        if(sum == 0) return 1;
        if(ind < 0) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        //not take

        int ans = f(nums, ind-1, sum);
        //take
        if((sum - nums[ind]) >= 0)
        ans |= f(nums, ind-1, sum - nums[ind]);

        return dp[ind][sum] = ans;

    }
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum&1)) return false;
        sum /= 2;
        for(int i = 0; i<220; i++)
        {
            for(int j = 0; j<100000; j++)
            {
                dp[i][j] = -1;
            }
        }
        return f(nums, nums.size()-1, sum);
    }
};