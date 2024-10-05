class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> expected(26,0);
        for(auto x:s1){
            expected[x - 'a']++;
        }
        vector<int> actual(26,0);
        int sz = s1.size();
        unordered_map<char,int> m;
        for(int i = 0; i<sz; i++){
            actual[s2[i]-'a']++;
        }

        if(actual == expected) return true;

        for(int i = 1; i+sz-1<s2.size(); i++){
            actual[s2[i-1]-'a']--;
            actual[s2[i+sz-1]-'a']++;
            if(actual == expected) return true;
        }

        return false;
    }

};