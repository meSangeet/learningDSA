class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int longest = 0;
        int current_length = 0;
        
        for (int num : nums) {
            if (num == max_val) {
                current_length++;
                longest = max(longest, current_length);
            } else {
                current_length = 0;
            }
        }
        
        return longest;
    }
};