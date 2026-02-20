class Solution {
public:
    string makeLargestSpecial(string s) {
        int start = 0;
        string ans = "";
        int l = s.length();
        vector<string> substrs;
        int sum = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '1') sum++;
            else sum--;

            if(sum == 0){
                string curMidMax = "";
                if(start < i){
                    string subs = s.substr(start+1, i - start - 1);
                    curMidMax = makeLargestSpecial(subs);
                }
                string curMax = "";
                curMax.push_back(s[start]);
                curMax += curMidMax;
                curMax.push_back(s[i]);
                substrs.push_back(curMax);
                start = i+1;
            }
            sort(substrs.begin(), substrs.end(), greater<string>());
        }
        for(string x : substrs) ans += x;
        return ans;
    }
};