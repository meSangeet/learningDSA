class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto x : edges){
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        map<int,int> m;
        vector<int> root(n, -1);
        for(int i = 0; i<n; i++){
            if(root[i] != -1) continue;
            int nd = (1 << 25);
            nd--;
            queue<int> q;
            q.push(i);
            root[i] = i;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto x : graph[node]){
                    if(root[x.first] == -1){
                        q.push(x.first);
                        root[x.first] = i;
                    }
                    nd &= x.second;
                }
            }
            m[i] = nd;
        }

        vector<int> ans;
        for(auto x : query){
            int a = x[0];
            int b = x[1];
            if(root[a] != root[b]){
                ans.push_back(-1);
                continue;
            }
            
            ans.push_back(m[root[a]]);
        }

        return ans;
    }
};