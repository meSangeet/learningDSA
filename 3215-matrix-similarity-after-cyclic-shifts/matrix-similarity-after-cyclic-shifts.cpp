class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i&1){
                    if(mat[i][(j-k+m)%m]==mat[i][j]) continue;
                    else return false;
                }
                else{
                    if(mat[i][(j+k)%m]==mat[i][j]) continue;
                    else return false;
                }
            }
        }
        return true;
    }
};