class Solution {
public:
    bool hasMatch(string s, string p) {
        string a = "", b = "";
        int n = p.length();
        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(p[i] == '*') {
                flag = false;
            } else if(flag) {
                a.push_back(p[i]);
            } else {
                b.push_back(p[i]);
            }
        }

        auto idx1 = s.find(a);
        if (idx1 == string::npos) {
            return false; 
        }

        auto idx2 = s.find(b, idx1 + a.length());
        if (idx2 == string::npos) {
            return false; 
        }

        return true;
    }
};
