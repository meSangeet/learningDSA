class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double len = 0.0;
        
        for (auto &x : dimensions) {
            double l = x[0];
            double b = x[1];
            double diag = sqrt(l * l + b * b);
            int area = x[0] * x[1];
            
            if (diag > len) {
                len = diag;
                ans = area;
            } else if (fabs(diag - len) < 1e-9) { // diagonals equal
                ans = max(ans, area);
            }
        }
        
        return ans;
    }
};
