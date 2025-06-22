class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int sz = 0;
        int l = s.length();
        vector<string> ans;
        int i = 0; 
        string cur = "";
        while(i < l){
            sz++;
            cur.push_back(s[i]);
            if(sz == k){
                ans.push_back(cur);
                cur = "";
                sz = 0;
            }
            i++;
        }

        if(sz > 0){
            while(sz < k){
                cur.push_back(fill);
                sz++;
            }
            ans.push_back(cur);
        }

        return ans;
    }
};