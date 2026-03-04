class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int count = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(mat[i][j] == 0) continue;

                bool flag = true;

                // Check row
                for(int k = 0; k < cols; k++){
                    if(k != j && mat[i][k] == 1){
                        flag = false;
                        break;
                    }
                }

                // Check column
                for(int k = 0; k < rows; k++){
                    if(k != i && mat[k][j] == 1){
                        flag = false;
                        break;
                    }
                }

                if(flag) count++;
            }
        }

        return count;
    }
};