class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;

        while (true) {
            // check if already non-decreasing
            bool ok = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;

            // find adjacent pair with minimum sum
            int idx = 0;
            int mn = nums[0] + nums[1];
            for (int i = 1; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < mn) {
                    mn = s;
                    idx = i;
                }
            }

            // merge that pair
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            ans++;
        }

        return ans;
    }
};
