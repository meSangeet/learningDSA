class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int length = 2; length < n + 2; ++length) { // length of subarray
            for (int left = 0; left + length < n + 2; ++left) {
                int right = left + length;
                for (int k = left + 1; k < right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left] * nums[k] * nums[right] + dp[left][k] + dp[k][right]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
