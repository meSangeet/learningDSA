class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        string res = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    while (!pq.empty()) {
                        int ind= -pq.top().second;
                        pq.pop();
                        if (ind< res.size() &&res[ind] != '#') {
                            res[ind] = '#';
                            break;
                        }
                    }
                }
            } else {
                res += s[i];
                pq.push({s[i], -(static_cast<int>(res.size()) - 1)});
            }
        }

        string ans = "";
        for (char ch : res) {
            if (ch != '#') {
                ans += ch;
            }
        }
        return ans;
    }
};