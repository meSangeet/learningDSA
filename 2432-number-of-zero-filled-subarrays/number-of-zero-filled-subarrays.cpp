class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cur = 0;
        for(int x : nums){
            if(x == 0){
                cur++;
                ans += cur;
            }else{
                cur = 0;
            }
        }

        return ans;
    }
};