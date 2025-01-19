class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r = heightMap.size(), c = heightMap[0].size();
        
        //let's keep the shit matrix aside
        if (r <= 2 || c <= 2) return 0;

        //once it is done it is done
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        //boundary se toh pani baahar chala jayega toh waha se shuru karo
        for (int i = 0; i < r; ++i) {
            for (int j : {0, c - 1}) { // Left and right boundaries
                pq.push({heightMap[i][j], {i, j}});
                //these bitches got to be marked true
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < c; ++j) {
            for (int i : {0, r - 1}) { // Top and bottom boundaries
                if (!visited[i][j]) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        //idhar chala mai udhar chala
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int waterTrapped = 0;

        //now let me go in <ahh>
        while (!pq.empty()) {
            auto [currentHeight, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            // Let's explore all the directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check if the new cell is within bounds and not visited yet.
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny]) {
                    // If the neighboring cell is lower than the current boundary,
                    // it can trap water!
                    waterTrapped += max(0, currentHeight - heightMap[nx][ny]);

                    // Update the height of the neighboring cell to the max of its own height and the current boundary height.
                    pq.push({max(currentHeight, heightMap[nx][ny]), {nx, ny}});
                    
                    // Mark it as visited to avoid processing it again.
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;
    }
};
//Nice Question
//Good Work Leetcode