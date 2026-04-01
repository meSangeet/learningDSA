#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Robot {
        int pos, hp, id;
        char dir;
    };

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;
        
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], i, directions[i]});
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        stack<int> st; 
        for (int i = 0; i < n; i++) {
            if (robots[i].dir == 'R') {
                st.push(i);
                continue;
            }

            while (!st.empty() && robots[i].hp > 0) {
                int j = st.top();
                
                if (robots[j].hp == robots[i].hp) {
                    robots[i].hp = 0;
                    robots[j].hp = 0;
                    st.pop();
                } else if (robots[j].hp > robots[i].hp) {
                    robots[j].hp -= 1;
                    robots[i].hp = 0;
                } else {
                    robots[i].hp -= 1;
                    robots[j].hp = 0;
                    st.pop();
                }
            }
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> res;
        for (auto& r : robots) {
            if (r.hp > 0) res.push_back(r.hp);
        }
        return res;
    }
};