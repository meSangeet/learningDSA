class Solution {
public:
    int calculate2(int a, int b, int c, int pp) {
        // If we select b and c
        int p1 = max(b, c) + max(a, pp);
        int p2 = max(a, b) + max(c, pp);
        int p3 = max(a, c) + max(b, pp);
        return min({p1, p2, p3});
    }

    int calculate(int a, int b, int c) {
        return max({a, b, c}) + min({a, b, c});
    }
    
    int minCost(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } 
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int pp = -1;
        bool flag = false;

        if (n % 2 == 0) {
            pp = nums.back();
            nums.pop_back();
            n--;
            flag = true;
        }

        map<int, int> dp;
        for (int i = 0; i < n - 2; i++) {
            int a = nums[i];
            int val;
            if (!flag)
                val = calculate(a, nums[n - 2], nums[n - 1]);
            else 
                val = calculate2(a, nums[n - 2], nums[n - 1], pp);
            dp[i] = val;
        }

        for (int i = n - 4; i >= 1; i -= 2) {
            map<int, int> temp;
            for (int j = 0; j < i; j++) {
                int pos1 = max(nums[j], nums[i]) + dp[i + 1];
                int pos2 = max(nums[j], nums[i + 1]) + dp[i];
                int pos3 = max(nums[i], nums[i + 1]) + dp[j];
                temp[j] = min({pos1, pos2, pos3});
            }
            dp = temp;
        }

        return dp[0];
    }
};