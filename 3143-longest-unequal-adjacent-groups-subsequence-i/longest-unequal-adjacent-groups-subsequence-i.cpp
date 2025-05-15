class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int cur = -1;
        int n = words.size();
        for(int i = 0; i<n; i++){
            if(cur == -1){
                ans.push_back(words[i]);
                cur = groups[i];
                continue;
            }

            if(groups[i] != cur){
                cur = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};