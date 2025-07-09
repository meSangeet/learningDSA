class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> adj;
    vector<int> disc, low;
    int time;

    void dfs(int u, int parent) {
        disc[u] = low[u] = time++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        disc.assign(n, -1);
        low.assign(n, -1);
        time = 0;
        dfs(0, -1);
        return res;
    }
};
