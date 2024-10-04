class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        
        bitset<10001> bits(1);  // Assuming max sum <= 20000
        for (int num : nums) {
            bits |= bits << num;
        }
        
        return bits[target];
    }
};