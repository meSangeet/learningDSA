class Solution {
public:
    bool isVowel(char x){
        if(x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size()+1, 0);
        for(int i = 0; i < words.size(); i++){
            if(isVowel(words[i][0]) and isVowel(words[i].back())){
                pref[i+1] = pref[i]+1;
            }else{
                pref[i+1] = pref[i];
            }
        }

        vector<int> ans;
        for(auto x : queries){
            int a = x[0];
            int b = x[1];
            ans.push_back(pref[b+1] - pref[a]);
        }

        return ans;
    }
};