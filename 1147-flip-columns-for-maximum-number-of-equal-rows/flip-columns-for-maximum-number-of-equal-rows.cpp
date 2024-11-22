class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> mp;  

        for (auto row : matrix) {
            int first = row[0];
            string c = "";
            for (int i = 0; i < row.size(); i++) {
                c += (first == row[i]) ? '1' : '0';
            }
            mp[c]++;  
        }

        int mx = 0;
        for (auto val : mp) {
            mx = max(val.second, mx);
        }
        return mx; 
    }
};