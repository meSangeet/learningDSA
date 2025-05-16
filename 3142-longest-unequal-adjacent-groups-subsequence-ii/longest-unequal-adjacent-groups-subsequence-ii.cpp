class Solution {
public:
    bool validHammingDistance(string s1, string s2){
        int count = 0;
        int n = s1.length();
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) count++;
            if(count > 1) return false; 
        }
        return (count == 1) ? true : false;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,-1);
        dp[0] = 1;
        vector<string> anss = {words[0]};
        vector<vector<string>> vec(n);
        vec[0].push_back(words[0]);
        
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            //look for previous satisfying word
            int ans = 0;
            vector<string> temp;
            for(int j = i - 1; j >= 0; j--){
                if(words[j].length() == words[i].length() and groups[i] != groups[j]){
                    if(validHammingDistance(words[i], words[j])){
                        if(dp[j] > ans){
                            ans = dp[j];
                            temp = vec[j];
                        }
                    }
                }
            }
            ans++;
            temp.push_back(words[i]);
            vec[i] = temp;
            dp[i] = ans;
            if(ans >= maxLen){
                anss = temp;
            }
            // cout<<i<<" - ";
            // if(vec[i].size() == 0){
            //     cout<<endl;
            //     continue;
            // }
            // for(int k = 0; k < vec[i].size(); k++){
            //     cout<<vec[i][k]<<" ";
            // }
            // cout<<endl;
            maxLen = max(ans, maxLen);
        }
        return anss;
    }
};
