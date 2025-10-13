class Solution {
public:
    bool isAna(string a, string b){
        vector<int> f1(26, 0), f2(26, 0);
        if(a.length() != b.length()) return false;
        for(char x : a){
            f1[x - 'a']++;
        }
        for(char x : b){
            f2[x - 'a']++;
        }
        for(int i = 0; i<f1.size(); i++){
            if(f1[i] != f2[i]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> s;
        for(int i = words.size()-1; i>=0; i--){
            string x = words[i];
            if(!s.empty()){
                if(isAna(s.top(), x)){
                    s.pop();
                    s.push(x);
                }else{
                    s.push(x);
                }
            }else{
                s.push(x);
            }
        }

        vector<string> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};