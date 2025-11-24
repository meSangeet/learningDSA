class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num = 0;
        vector<bool> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            num *= 2;
            num %= 5;
            if(nums[i] == 1){
                num += 1;
            }

            if(num%5 == 0){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};