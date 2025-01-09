class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i<n; i++){
            string word = words[i];
            if(word.length() >= pref.length()){
                if(word.substr(0, pref.length()) == pref) ans++;
            }
        }

        return ans;
    }
};