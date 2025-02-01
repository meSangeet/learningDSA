class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int p = nums[0]%2;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]%2 == p){
                return false;
            }
            p = nums[i]%2;
        }
        return true;
    }
};