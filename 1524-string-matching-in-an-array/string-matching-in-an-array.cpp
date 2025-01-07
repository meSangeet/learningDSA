class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0; i<n; i++){
            string word = words[i];
            for(int j = 0; j<n; j++){
                if(i != j){
                    if(words[j].find(word) != string::npos){
                        ans.push_back(word);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};