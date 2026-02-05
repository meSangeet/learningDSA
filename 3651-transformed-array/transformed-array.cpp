class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(int i = 0; i < n; i++) {
            int targetIndex = ((i + nums[i]) % n + n) % n;
            res.push_back(nums[targetIndex]);
        }
        
        return res;
    }
};