class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> left(n + 1), right(n + 1);
        
        // Generate all subset sums for the first half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    count++;
                }
            }
            left[count].push_back(sum);
        }
        
        // Generate all subset sums for the second half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[n + i];
                    count++;
                }
            }
            right[count].push_back(sum);
        }
        
        // Sort the sums for binary search
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        
        int minDiff = INT_MAX;
        
        // Find the best combination
        for (int i = 0; i <= n; i++) {
            for (int leftSum : left[i]) {
                int target = (totalSum - 2 * leftSum) / 2;
                auto it = lower_bound(right[n - i].begin(), right[n - i].end(), target);
                
                if (it != right[n - i].end()) {
                    minDiff = min(minDiff, abs(totalSum - 2 * (leftSum + *it)));
                }
                if (it != right[n - i].begin()) {
                    it--;
                    minDiff = min(minDiff, abs(totalSum - 2 * (leftSum + *it)));
                }
            }
        }
        
        return minDiff;
    }
};