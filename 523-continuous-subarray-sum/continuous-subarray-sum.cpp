#define ll long long
class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long, int> m;
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(i > 0 and nums[i] == 0 and nums[i-1] == 0) return true;
            sum += nums[i];
            ll mod = sum%k;
            if(mod == 0 and i >0) return true;
            if(m.find(mod) != m.end()){
                int ind = m[mod];
                if(ind < i-1){
                    return true;
                }
            }else
            m[mod] = i;
        }
        return false;
    }
};