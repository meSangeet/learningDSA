class Solution {
    bool hasCycle(int color, unordered_set<int>& visiting, unordered_set<int>& processed,
                  unordered_map<int, vector<int>>& graph) {
        if (visiting.count(color)) return true;

        if (processed.count(color)) return false;

        visiting.insert(color);

        for (int dependent : graph[color]) {
            if (hasCycle(dependent, visiting, processed, graph)) {
                return true;
            }
        }

        visiting.erase(color);
        processed.insert(color);

        return false;
    }

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int, int> l, r, t, b; 
        set<int> colors; 

        int rows = targetGrid.size();
        int cols = targetGrid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int color = targetGrid[i][j];
                colors.insert(color);
                if (l.find(color) == l.end()) {
                    l[color] = j;
                    r[color] = j;
                    t[color] = i;
                    b[color] = i;
                } else {
                    l[color] = min(l[color], j);
                    r[color] = max(r[color], j);
                    t[color] = min(t[color], i);
                    b[color] = max(b[color], i);
                }
            }
        }

        unordered_map<int, vector<int>> graph;
        for (int color : colors) {
            for (int i = t[color]; i <= b[color]; i++) {
                for (int j = l[color]; j <= r[color]; j++) {
                    int curColor = targetGrid[i][j];
                    if (curColor != color) {
                        graph[color].push_back(curColor); 
                    }
                }
            }
        }

        unordered_set<int> visiting;  
        unordered_set<int> processed;

        for (int color : colors) {
            if (hasCycle(color, visiting, processed, graph)) {
                return false;
            }
        }

        return true;
    }
};
