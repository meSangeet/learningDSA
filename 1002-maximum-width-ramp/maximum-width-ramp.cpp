class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
int n = nums.size();
        stack<int> stk;
        
        // First pass: Build a stack of indices where the corresponding elements are in descending order.
        for (int i = 0; i < n; i++) {
            if (stk.empty() || nums[stk.top()] > nums[i]) {
                stk.push(i);
            }
        }

        int maxWidth = 0;
        // Second pass: Iterate from the end to calculate the maximum width of the ramp.
        for (int j = n - 1; j >= 0; j--) {
            while (!stk.empty() && nums[stk.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - stk.top());
                stk.pop();
            }
        }
        
        return maxWidth;

    }
};