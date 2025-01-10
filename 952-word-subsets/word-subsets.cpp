class Solution {
    bool checkSubsequence(const string s1, const string s2){
        int m = s1.length();
        int n = s2.length();
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        if(i == m) return true;
        return false;
    }
public:
    vector<string> wordSubsets(vector<string>& wordss1, vector<string>& wordss2) {
        vector<int> tempp(26,0);
        vector<string> ans;
        for(string s : wordss2){
            vector<int> temp(26,0);
            for(char x : s){
                temp[x-'a']++;
                if(temp[x-'a'] > tempp[x-'a']){
                    tempp[x-'a'] = temp[x-'a'];
                }
            }
        }
        for(string s : wordss1){
            vector<int> temp(26,0);
            for(char x : s){
                temp[x-'a']++;
            }
            bool flag = true;

            for(int i = 0; i<26; i++){
                if(temp[i] < tempp[i]){
                    flag = false;
                    break;
                }
            }

            if(flag) ans.push_back(s);
        }
        return ans;
    }
};