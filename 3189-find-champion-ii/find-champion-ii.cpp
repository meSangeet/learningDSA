class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> par(n, true);
        for(int i = 0; i<edges.size(); i++){
            par[edges[i][1]] = false;
        }

        int ans = -1;

        for(int i = 0; i<n; i++){
            if(par[i]){
                if(ans != -1){
                    return -1;
                }

                ans = i;
            }
        }

        return ans;
    }
};