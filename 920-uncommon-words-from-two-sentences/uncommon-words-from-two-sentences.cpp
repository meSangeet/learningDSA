class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m;
        string curr = "";
        s1 += " ";
        s1 += s2;
        for(auto x:s1){
            if(x == ' '){
                m[curr]++;
                curr = "";
            }else{
                curr.push_back(x);
            }
        }
        m[curr]++;
        vector<string> ans;

        for(auto x:m){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};