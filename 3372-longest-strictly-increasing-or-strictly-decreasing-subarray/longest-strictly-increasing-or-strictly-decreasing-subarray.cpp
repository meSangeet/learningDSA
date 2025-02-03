class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool inc = true;
        int ma = 1;
        int cur = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                if(inc){
                    cur++;
                    ma = max(ma, cur);
                }else{
                    inc = true;
                    cur = 2;
                    ma = max(ma, cur);
                }
            }else if(nums[i] < nums[i-1]){
                if(inc){
                    inc = false;
                    cur = 2;
                    ma = max(ma, 2);
                }else{
                    inc = false;
                    cur++;
                    ma = max(ma, cur);
                }
            }else{
                cur = 1;
            }
        }
        return ma;
    }

};