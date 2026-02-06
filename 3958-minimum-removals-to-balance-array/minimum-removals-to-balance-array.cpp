class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1e9,sz=nums.size();
        for(int i=0; i<sz; i++){
            int ub=upper_bound(nums.begin(),nums.end(),nums[i]*1ll*k)-nums.begin();
            ans=min(ans,i+(sz-ub));
        }
        return ans;
    }
};