class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int level = nums.size() - 1; level > 0; --level) {
            for (int i = 0; i < level; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};