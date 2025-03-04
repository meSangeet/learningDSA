class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;
        if(k == nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        map<int,int> m;
        for(int x : nums){
            m[x]++;
        }
        if(k == 1){
            for(auto x : m){
                if(x.second == 1){
                    ans = x.first;
                }
            }
            return ans;
        }
        if(m[nums[0]] == 1){
            ans = max(ans, nums[0]);
        }
        if(m[nums.back()] == 1){
            ans = max(ans, nums.back());
        }
        return ans;
    }
};