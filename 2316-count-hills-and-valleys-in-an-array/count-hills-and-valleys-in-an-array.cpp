class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i<n-1; i++){
            int lef = -1, ri = -1;
            int j = i-1;
            if(nums[i] == nums[i-1]) continue;
            while(j >= 0){
                if(nums[j] != nums[i]){
                    lef = nums[j];
                    break;
                }
                j--;
            }
            j = i+1;
            while(j < n){
                if(nums[j] != nums[i]){
                    ri = nums[j];
                    break;
                }
                j++;
            }
            if(lef == -1 || ri == -1) continue;
            int bet = nums[i];
            if(bet > lef and bet > ri){
                ans++;
            }
            if(bet < lef and bet < ri){
                ans++;
            }
        }
        return ans;
    }
};