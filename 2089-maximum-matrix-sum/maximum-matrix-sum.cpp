#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0;
        int r = matrix.size();
        int c = matrix[0].size();

        int count = 0;
        int miin = INT_MAX;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(matrix[i][j] < 0){
                    count++;
                }

                ans += abs(matrix[i][j]);
                miin = min(miin, abs(matrix[i][j]));
            }
        }

        if(count%2 == 0){
            return ans;
        }

        ans -= 2*miin;

        return ans;
    }
};