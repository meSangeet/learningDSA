class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xors = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) xors ^= nums[i];
        return xors;
    }
};