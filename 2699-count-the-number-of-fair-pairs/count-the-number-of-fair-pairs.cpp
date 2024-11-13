#define ll long long

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        vector<int> arr(nums);
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for(int i = 0; i<nums.size()-1; i++){
            //for lower
            // ll cur = -1;
            ll tar = lower - nums[i];
            ll l = 0, r = nums.size()-1;
            ll mid = l + (r-l)/2;
            // while(l < r){
            //     if(nums[mid] >= tar){
            //         cur = mid;
            //         r = mid-1;
            //     }else{
            //         l = mid+1;
            //     }
            //     mid = l + (r-l)/2;
            // }

            auto cur = (lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]));


            // if(cur == -1){
            //     continue;
            // }

            l = 0, r = nums.size()-1;

            // tar = upper - nums[i];
            // mid = l + (r-l)/2;
            // while(l < r){
            //     if(nums[mid] <= tar){
            //         bur = mid;
            //         l = mid+1;
            //     }else{
            //         r = mid-1;
            //     }

            //     mid = l + (r-l)/2;
            // }

            auto bur = (upper_bound(nums.begin()+i+1, nums.end(), upper - nums[i]));
            // if(bur != -1){
                ans += bur - cur;
            // }
        }
        return ans;
    }
};