class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        size_t n = mat.size(), m = mat[0].size();
        std::array<int, 100> rows{}, cols{};
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (mat[i][j]) {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        uint16_t output = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (mat[i][j] && rows[i] == 1 && cols[j] == 1) ++output;
            }
        }
        return output;
    }
};