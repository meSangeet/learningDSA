class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int x : nums){
            m[x]++;
        }
        int ans = 0;
        for(auto x : m){
            int num = x.first;
            int tar = num+1;
            if(m.count(tar)){
                ans = max(ans, x.second + m[tar]);
            }
        }

        return ans;
    }
};