class Solution {
public:
    int kadane(vector<int> a){
        int n = a.size();
        int ans = 0;
        int cur = 0;
        for(int i = 0; i<n; i++){
            cur += a[i];
            if(cur <= 0){
                cur = 0;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> num;
        for(int x : nums){
            num.push_back(-1*x);
        }
        return max(kadane(num), kadane(nums));
    }
};