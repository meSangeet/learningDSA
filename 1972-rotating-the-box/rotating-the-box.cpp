class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r = box.size();
        int c = box[0].size();
        
        // Process each row to make stones fall to the right
        for (int i = 0; i < r; i++) {
            int empty = c - 1; // Start from the last column
            for (int j = c - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    // Obstacle found, reset the empty pointer
                    empty = j - 1;
                } else if (box[i][j] == '#') {
                    // Stone found, move it to the farthest empty spot
                    box[i][j] = '.';
                    box[i][empty] = '#';
                    empty--;
                }
            }
        }

        // Rotate the box 90 degrees clockwise
        vector<vector<char>> ans(c, vector<char>(r));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[j][r - i - 1] = box[i][j];
            }
        }

        return ans;
    }
};
