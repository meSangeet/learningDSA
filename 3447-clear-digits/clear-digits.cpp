class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(ans.size() == 0){
                ans.push_back(s[i]);
            }else if(s[i] >= '0' and s[i] <= '9'){
                if(ans.back() >= 'a' and ans.back() <= 'z'){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }

            }else{
                ans.push_back(s[i]);
            }

        }

        //cb34
        return ans;
    }
};