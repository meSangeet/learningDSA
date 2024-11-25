class Solution {
public:
    int dir[4] = {+1, -1, 3, -3}; 
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += to_string(board[i][j]); 
            }
        }
        string target = "123450"; 
        unordered_map<string, int> vis; 
        queue<string> q;
        q.push(s); 
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string t = q.front();
                q.pop();
                if (t == target)
                    return cnt;
                if (vis.find(t) != vis.end())
                    continue;
                vis[t] = 1; 
                int ind = 0; 
                for (int i = 0; i < 6; i++) {
                    if (t[i] == '0') {
                        ind = i;
                        break;
                    }
                }
                for (int i = 0; i < 4; i++) {
                    int tempdir = ind + dir[i];
                    if (tempdir < 0 || tempdir >= 6)
                        continue; 
                           if ((ind % 3 == 2 && tempdir % 3 == 0) || (ind % 3 == 0 && tempdir % 3 == 2))
                        continue; 
                    string copyOfT = t; 
                    swap(copyOfT[ind], copyOfT[tempdir]);
                    if (vis.find(copyOfT) == vis.end()) { 
                        q.push(copyOfT);
                    }
                }
            }
            cnt++; 
        }
        return -1;
    }
};