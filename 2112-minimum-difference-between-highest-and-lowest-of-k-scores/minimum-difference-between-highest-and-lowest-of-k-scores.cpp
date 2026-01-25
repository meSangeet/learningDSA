class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(k == 0 || k == 1) return 0;
        int ans = INT_MAX;
        int second = k-1, fir = 0;
        while(second < n){
            ans = min(ans, nums[second] - nums[fir]);
            second++;
            fir++;
        }
        return ans;
    }
};