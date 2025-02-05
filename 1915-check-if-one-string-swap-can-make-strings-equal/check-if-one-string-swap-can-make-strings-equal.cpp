class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        //almost equal hmmm
        char c = '*';
        char d, e;
        bool flag = false;
        bool comp = false;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                if(flag){
                    if(c != '*') return false;
                    if(s2[i] != d || s1[i] != e) return false;
                    c = '_';
                    comp = true;
                }else{
                    flag = true;
                    d = s1[i];
                    e = s2[i];
                }
            }
        }
        if(flag and !comp) return false;
        return true;
    }
};