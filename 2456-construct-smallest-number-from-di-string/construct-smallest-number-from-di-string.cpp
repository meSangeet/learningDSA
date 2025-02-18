class Solution {
public:
    bool func(int i, int sz, char prev, set<char> &s, string &pattern, string &cur){
        if(i == sz) return true;
        if(pattern[i] == 'D'){
            //check for all lower characters from start
            for(char p = '1'; p<prev; p++){
                if(!s.count(p)){
                    s.insert(p);
                    cur.push_back(p);
                    if(func(i+1, sz, p, s, pattern, cur)){
                        return true;
                    }
                    cur.pop_back();
                    s.erase(p);
                }
            }
        }else{
            for(char p = prev+1; p<='9'; p++){
                if(!s.count(p)){
                    s.insert(p);
                    cur.push_back(p);
                    if(func(i+1, sz, p, s, pattern, cur)){
                        return true;
                    }
                    cur.pop_back();
                    s.erase(p);
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string ans = "";
        for(int i = 1; i<=9; i++){
            string cur = "";
            set<char> s;
            char p = '0'+i;
            cur.push_back(p);
            s.insert(p);
            if(func(0,pattern.size(),p,s,pattern, cur)){
                return cur;
            }
        }
        return ans;
    }
};