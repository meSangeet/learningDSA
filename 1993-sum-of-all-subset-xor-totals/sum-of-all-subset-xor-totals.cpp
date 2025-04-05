class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int low = 0;
        int high = 0;
        int n = nums.size();
        high = (1 << (n));
        // high--;
        int ans = 0;
        for(int mask = 0; mask < high; mask++){
            int no = mask;
            int ind = 0;
            int cur = 0;
            while(no){
                if(no&1){
                    cur ^= nums[ind];
                }
                ind++;
                no /= 2;
            }
            ans += cur;
        }
        return ans;
    }
};