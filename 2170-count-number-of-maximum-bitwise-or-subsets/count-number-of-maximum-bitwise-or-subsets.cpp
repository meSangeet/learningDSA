class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }

        return countSubsets(nums, 0, 0, max_or);
    }

private:
    int countSubsets(const vector<int>& nums, int index, int current_or, int max_or) {
        if (index == nums.size()) {
            return (current_or == max_or) ? 1 : 0;
        }

        int count = countSubsets(nums, index + 1, current_or, max_or); // Exclude
        count += countSubsets(nums, index + 1, current_or | nums[index], max_or); // Include

        return count;
    }
};