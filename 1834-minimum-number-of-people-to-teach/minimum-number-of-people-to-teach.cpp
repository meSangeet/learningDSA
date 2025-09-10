class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSets(m);
        unordered_map<int, int> freq;

        // Build language sets and frequency map
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                langSets[i].insert(l);
                freq[l]++;
            }
        }

        // Sort languages by frequency
        vector<pair<int,int>> freqList(freq.begin(), freq.end());
        sort(freqList.begin(), freqList.end(),
             [](auto& a, auto& b){ return a.second > b.second; });

        int ans = INT_MAX;

        // Try each language
        for (auto& [lang, _] : freqList) {
            unordered_set<int> needTeach;

            for (auto& f : friendships) {
                int u = f[0] - 1, v = f[1] - 1;
                bool can = false;

                // Check if already share some language
                for (int l : langSets[u]) {
                    if (langSets[v].count(l)) {
                        can = true;
                        break;
                    }
                }

                // If not, mark users who don’t know this candidate language
                if (!can) {
                    if (!langSets[u].count(lang)) needTeach.insert(u);
                    if (!langSets[v].count(lang)) needTeach.insert(v);
                }
            }

            ans = min(ans, (int)needTeach.size());
            if (ans == 0) return 0; // optimal early exit
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};