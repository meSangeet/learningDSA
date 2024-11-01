class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int l = s.length();
        if(s.length() == 1) return s;
        char sec = s[0];
        char fir = s[1];
        ans.push_back(sec);
        ans.push_back(fir);
        for(int i = 2; i<l; i++){
            char cur = s[i];
            if(s[i] != fir || s[i] != sec){
                ans.push_back(s[i]);
                sec = fir;
                fir = cur;
            }
        }
        return ans;
    }
};