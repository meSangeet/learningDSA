class Solution {
public:
    set<int> func(vector<vector<int>> &adj, int node, vector<set<int>> &vec, vector<bool> &visited) {
        visited[node] = true;
        set<int> s;
        s.insert(node);

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                set<int> temp = func(adj, nei, vec, visited);
                s.insert(temp.begin(), temp.end());
            } else {
                s.insert(vec[nei].begin(), vec[nei].end());
            }
        }

        vec[node] = s;
        return s;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<vector<int>> adj(numCourses);
        for (auto x : prerequisites) {
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }

        vector<bool> ans;
        vector<set<int>> vec(numCourses); 
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                func(adj, i, vec, visited);
            }
        }

        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            if (vec[v].find(u) != vec[v].end()) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
