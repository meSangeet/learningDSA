class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> color(n, -1); // -1 means uncolored
        vector<bool> visited(n, false);
        int maxGroups = 0;

        function<bool(int)> isBipartite = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 0; // Color first node as 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) { // Not visited yet
                        color[v] = 1 - color[u]; // Assign opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Not bipartite
                    }
                }
            }
            return true;
        };

        auto bfsMaxDepth = [&](int start) {
            queue<int> q;
            vector<int> dist(n, -1);
            q.push(start);
            dist[start] = 0;
            int maxDepth = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        maxDepth = max(maxDepth, dist[v]);
                        q.push(v);
                    }
                }
            }
            return maxDepth + 1;
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!isBipartite(i)) {
                    return -1; // Graph is not bipartite
                }

                // Find the max depth for this connected component
                int maxDepth = 0;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    maxDepth = max(maxDepth, bfsMaxDepth(node));

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                maxGroups += maxDepth;
            }
        }

        return maxGroups;
    }
};
