class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]-i]++;
        }
        long long n = nums.size();
        long long sub = 0;
        for(auto x : m){
            long long no = x.second;
            no *= (no-1);
            no /= 2;
            sub += no;
        }
        long long ans = n * (n-1);
        ans /= 2;
        ans -= sub;
        return ans;
    }
};