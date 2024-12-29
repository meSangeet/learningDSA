class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) { // If such an element is found
            int j = n - 1;

            // Step 2: Find the smallest element larger than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the subarray nums[i+1:]
        reverse(nums.begin() + i + 1, nums.end());
    }
};