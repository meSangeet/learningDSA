class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, vector<pair<int, int>>> mp;

        for (int i = 0; i < q; i++) {
            int lef = min(queries[i][0], queries[i][1]);
            int ri = max(queries[i][0], queries[i][1]);

            if (lef == ri) {
                ans[i] = lef;
                continue;
            }

            if (heights[ri] > heights[lef]) {
                ans[i] = ri;
                continue;
            }

            mp[ri].push_back({heights[lef], i});
        }

        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first < heights[i]) {
                int ind = pq.top().second;
                ans[ind] = i;
                pq.pop();
            }

            for (auto x : mp[i]) {
                pq.push(x);
            }
        }

        return ans;
    }
};
