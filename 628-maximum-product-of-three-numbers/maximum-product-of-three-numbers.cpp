class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> numsCp(nums);
        sort(numsCp.begin(), numsCp.end());
        int n = nums.size();
        return max({numsCp[n-1]*numsCp[n-2]*numsCp[n-3], numsCp[0]*numsCp[1]*numsCp[2], 
        numsCp[0]*numsCp[1]*numsCp[n-1]});
    }
};