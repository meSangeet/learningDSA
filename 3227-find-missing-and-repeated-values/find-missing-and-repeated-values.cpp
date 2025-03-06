class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,int> m;
        for(auto x : grid){
            for(auto y : x){
                m[y]++;
            }
        }
        vector<int> ans(2,-1);
        for(int i = 1; i<=n*n; i++){
            if(m[i] == 0){
                ans[1] = i;
            }
            if(m[i] == 2){
                ans[0] = i;
            }
        }
        return ans;
    }
};