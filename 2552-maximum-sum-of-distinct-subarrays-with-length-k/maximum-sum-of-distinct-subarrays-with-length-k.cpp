class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long cur = 0;
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i = 0; i<k-1; i++){
            m[nums[i]]++;
            cur += nums[i];
        }
        int del = 0;
        for(int i = k-1; i<n; i++){
            m[nums[i]]++;
            cur += nums[i];
            if(m.size() == k){
                ans = max(cur, ans);
            }

            int elem = nums[del];
            cur -= elem;
            m[elem]--;
            if(m[elem] == 0){
                m.erase(elem);
            }
            del++;
        }

        return ans;
    }
};