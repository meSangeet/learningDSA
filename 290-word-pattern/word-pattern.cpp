class Solution {
public:
    vector<string> func(string s){
        vector<string> ans;
        int cur = 0;
        string curStr = "";
        while(cur < s.length()){
            if(s[cur] == ' '){
                ans.push_back(curStr);
                curStr = "";
            }else{
                curStr.push_back(s[cur]);
            }
            cur++;
        }

        ans.push_back(curStr);
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> vec = func(s);
        // for(auto x : vec) cout<<x<<" ";
        // cout<<endl;
        cout<<vec.size();
        if(pattern.size() != vec.size()){
            return false;
        }
        map<string,char> m;
        map<char,string> mm;
        for(int i = 0; i<pattern.length(); i++){
            char pat = pattern[i];
            // cout<<i<<endl;
            string tar = vec[i];

            if(m.find(tar) != m.end()){
                if(m[tar] != pat){
                    return false;
                }
            }else{
                m[tar] = pat;
            }

            if(mm.find(pat) != mm.end()){
                if(mm[pat] != tar){
                    return false;
                }
            }else{
                mm[pat] = tar;
            }
        }
        return true;
    }
};