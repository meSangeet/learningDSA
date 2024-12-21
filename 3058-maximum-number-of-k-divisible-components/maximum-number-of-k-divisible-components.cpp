class Solution {
    int solve(int src, vector<vector<int>> &adj, int k, vector<int> &values, int &ans, vector<bool> &visited) {
        visited[src] = true;

        int modSum = values[src] % k;

        for (int child : adj[src]) {
            if (!visited[child]) {
                modSum += solve(child, adj, k, values, ans, visited);
                modSum %= k; 
            }
        }

        if (modSum == 0) {
            ans++;
            return 0; 
        }

        return modSum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        solve(0, adj, k, values, ans, visited);
        return ans;
    }
};
