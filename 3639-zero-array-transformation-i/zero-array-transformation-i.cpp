class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(auto q : queries){
            pre[q[0]]++;
            pre[q[1]+1]--;
        }
        int con = 0;
        for(int i = 0; i<n; i++){
            con += pre[i];
            int no = nums[i] - con;
            if(no > 0) return false;
        }
        return true;
    }
};