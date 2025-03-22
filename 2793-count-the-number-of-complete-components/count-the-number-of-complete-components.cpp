class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, int &nodes, int &edges){
        visited[node] = true;
        nodes++; // Counting nodes in the component
        edges += graph[node].size(); // Add all edges from this node

        for(int nei : graph[node]){
            if(!visited[nei]){
                dfs(graph, nei, visited, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int nodes = 0, edges = 0;
                dfs(graph, i, visited, nodes, edges);
                edges /= 2; // Since each edge is counted twice
                if(edges == (nodes * (nodes - 1)) / 2){
                    ans++;
                }
            }
        }

        return ans;
    }
};
