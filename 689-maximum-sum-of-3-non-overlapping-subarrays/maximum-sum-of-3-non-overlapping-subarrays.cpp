class Solution {
public:
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> subarray_sum(n - k + 1, 0);
    vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
    
    // Step 1: Calculate subarray sums of length k
    int current_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += nums[i];
    }
    subarray_sum[0] = current_sum;
    for (int i = 1; i <= n - k; ++i) {
        current_sum += nums[i + k - 1] - nums[i - 1];
        subarray_sum[i] = current_sum;
    }

    // Step 2: Calculate left max indices
    int max_index = 0;
    for (int i = 0; i < subarray_sum.size(); ++i) {
        if (subarray_sum[i] > subarray_sum[max_index]) {
            max_index = i;
        }
        left[i] = max_index;
    }

    // Step 3: Calculate right max indices
    max_index = subarray_sum.size() - 1;
    for (int i = subarray_sum.size() - 1; i >= 0; --i) {
        if (subarray_sum[i] >= subarray_sum[max_index]) {
            max_index = i;
        }
        right[i] = max_index;
    }

    // Step 4: Find the maximum sum of three non-overlapping subarrays
    vector<int> result(3, -1);
    int max_sum = 0;
    for (int j = k; j <= n - 2 * k; ++j) {
        int l = left[j - k];
        int r = right[j + k];
        int total_sum = subarray_sum[l] + subarray_sum[j] + subarray_sum[r];
        if (total_sum > max_sum) {
            max_sum = total_sum;
            result = {l, j, r};
        }
    }

    return result;
}
};