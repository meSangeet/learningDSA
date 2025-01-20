class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat[0].size();
        int m = mat.size();
        map<int,int> elemToRow, elemToCol;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                elemToRow[mat[i][j]] = i;
                elemToCol[mat[i][j]] = j;
            }
        }
        // for(auto x : elemToCol){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        vector<int> cols(n,0), rows(m,0);
        int ans = 0;
        // cout<<"track"<<endl;
        for(int x : arr){
            // cout<<x<<endl;
            cols[elemToCol[x]]++;
            rows[elemToRow[x]]++;
            // for(auto x : cols) cout<<x<<" ";
            // cout<<endl;
            // for(auto y : rows) cout<<y<<" ";
            // cout<<endl;
            ans++;
            if(cols[elemToCol[x]] == m || rows[elemToRow[x]] == n){
                return ans-1;
            }
        }

        return ans-1;
    }
};