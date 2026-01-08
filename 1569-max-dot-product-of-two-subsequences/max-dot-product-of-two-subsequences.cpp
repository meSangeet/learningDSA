class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i < 0 || j < 0) return -1e9;
        if (dp[i][j] != -1) return dp[i][j];

        
        int take = nums1[i] * nums2[j] + solve(nums1, nums2, i - 1, j - 1);
        int start_new = nums1[i] * nums2[j];
        int skip1 = solve(nums1, nums2, i - 1, j);
        int skip2 = solve(nums1, nums2, i, j - 1);

        return dp[i][j] = max({take, start_new, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, nums1.size() - 1, nums2.size() - 1);
    }
};