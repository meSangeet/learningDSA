class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<bool> visited(n, false);
        vector<int> count(n, 0);

        // Create a reversed adjacency list
        vector<vector<int>> neighbour(n);
        for (int i = 0; i < n; i++) {
            neighbour[favorite[i]].push_back(i);
        }

        // Function to calculate the max path length from a node
        auto maxLen = [&neighbour](int node, vector<bool>& visited) -> int {
            queue<pair<int, int>> q;
            q.push({node, 0});
            int ans = 0;
            while (!q.empty()) {
                auto [curNode, pathLen] = q.front();
                q.pop();
                ans = max(ans, pathLen);
                for (int nei : neighbour[curNode]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push({nei, pathLen + 1});
                    }
                }
            }
            return ans;
        };

        // Variables to track maximum lengths
        int maxCycleLen = 0, totalCoupleCycleLen = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int curNode = i;
                vector<int> stack;
                unordered_map<int, int> depth;

                // Detect cycle using a stack and depth map
                while (!visited[curNode]) {
                    visited[curNode] = true;
                    stack.push_back(curNode);
                    depth[curNode] = stack.size();
                    curNode = favorite[curNode];
                }

                // Handle detected cycle
                if (depth.count(curNode)) {
                    int cycleStart = curNode;
                    int cycleLength = stack.size() - depth[curNode] + 1;

                    if (cycleLength == 2) {
                        int node1 = stack.back();
                        int node2 = favorite[node1];
                        vector<bool> visitedSec(n, false);
                        visitedSec[node1] = true;
                        visitedSec[node2] = true;
                        totalCoupleCycleLen += 2 + maxLen(node1, visitedSec) + maxLen(node2, visitedSec);
                    } else {
                        maxCycleLen = max(maxCycleLen, cycleLength);
                    }
                }
            }
        }

        return max(maxCycleLen, totalCoupleCycleLen);
    }
};
