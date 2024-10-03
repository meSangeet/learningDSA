class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;
        for (int num : nums) {
            target = (target + num) % p;
        }
        
        if (target == 0) return 0;
        
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        
        int currSum = 0;
        int minLen = n;
        
        for (int i = 0; i < n; i++) {
            currSum = (currSum + nums[i]) % p;
            int complement = (currSum - target + p) % p;
            
            if (prefixSum.find(complement) != prefixSum.end()) {
                minLen = min(minLen, i - prefixSum[complement]);
            }
            
            prefixSum[currSum] = i;
        }
        
        return minLen < n ? minLen : -1;
    }
};