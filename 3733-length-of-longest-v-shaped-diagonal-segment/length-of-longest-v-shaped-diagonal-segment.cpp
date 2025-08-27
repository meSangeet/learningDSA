using a2i = std::array<int, 2>;
using a4a2i = std::array<a2i, 4>;
using a501a501a4a2i = std::array<std::array<a4a2i, 501>, 501>;

class Solution {
public:
    int dfs(int cx, int cy, int direction, bool turn, int target, const a4a2i &dirs, a501a501a4a2i &memo, const std::vector<std::vector<int>> &grid, const int &n, const int &m) {
        int nx = cx + dirs[direction][0];
        int ny = cy + dirs[direction][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != target) return 0;
        if (memo[nx][ny][direction][turn] != -1) return memo[nx][ny][direction][turn];
        int maxStep = dfs(nx, ny, direction, turn, 2 - target, dirs, memo, grid, n, m);
        if (turn) {
            maxStep = std::max(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target, dirs, memo, grid, n, m));
        }
        ++maxStep;
        memo[nx][ny][direction][turn] = maxStep;
        return maxStep;
    };

    int lenOfVDiagonal(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        a4a2i dirs = {a2i{1, 1}, a2i{1, -1}, a2i{-1, -1}, a2i{-1, 1}};
        a501a501a4a2i memo = {};
        for (auto &a : memo)
            for (auto &b : a)
                for (auto &c : b)
                    c.fill(-1);
        int output = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        output = std::max(output, dfs(i, j, direction, true, 2, dirs, memo, grid, n, m) + 1);
                    }
                }
            }
        }
        return output;
    }
};