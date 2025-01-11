class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> chars(26,0);
        for(char x : s){
            chars[x-'a']++;
        }

        int odd = 0;

        for(int i = 0; i<26; i++){
            if(chars[i]%2 == 1){
                odd++;
                chars[i]--;
            }
        }
        if(s.length() < k) return false;
        if(odd > k) return false;
        return true;
    }
};