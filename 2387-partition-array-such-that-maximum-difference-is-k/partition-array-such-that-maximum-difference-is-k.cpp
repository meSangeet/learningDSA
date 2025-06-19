class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int it = 0, n = nums.size(), cnt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] - nums[it] > k){
                cnt++;
                it = i;
            }
        }
        return cnt + 1;
    }
};