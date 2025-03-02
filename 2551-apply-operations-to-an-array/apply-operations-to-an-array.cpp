class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n-1; i++){
            if(nums[i] == 0) ct++;
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }

            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
        }

        if(nums[n-1] == 0) ct++;
        else ans.push_back(nums[n-1]);

        while(ct--) ans.push_back(0);

        return ans;
    }
};