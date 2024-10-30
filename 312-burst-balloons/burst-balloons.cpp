class Solution {
public:
    int dp(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if (left + 1 == right) return 0; // No balloon to burst
        if (memo[left][right] != -1) return memo[left][right];
        int maxCoins = 0;
        for (int k = left + 1; k < right; ++k) {
            int coins = nums[left] * nums[k] * nums[right] + dp(left, k, nums, memo) + dp(k, right, nums, memo);
            maxCoins = max(maxCoins, coins);
        }
        memo[left][right] = maxCoins;
        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        return dp(0, n + 1, nums, memo);
    }
};
