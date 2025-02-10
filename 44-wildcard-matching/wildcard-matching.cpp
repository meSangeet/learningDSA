class Solution {
public:
    bool isMatch(string s, string p) {
        // cout<<s<<" "<<p<<endl;
        int patLen = p.length();
        int tarLen = s.length();

        if(patLen == 0 and tarLen != 0) return false;
        if(patLen == 0 and tarLen == 0) return true;
        if(patLen != 0 and tarLen == 0){
            bool flag = true;
            for(char x : p){
                if(x != '*'){
                    return false;
                }
            }
            return true;
        } 
        vector<vector<bool> > dp(patLen, vector<bool> (tarLen, false));

        if(p[patLen-1] == '*'){
            for(int i = 0; i < tarLen; i++){
                dp[patLen-1][i] = true;
            }
            int i = patLen - 2;
            bool flag = true;
            while(i >= 0){
                if(p[i] == '*')
                    dp[i][tarLen-1] = true;
                else if(p[i] == s[tarLen-1] || p[i] == '?'){
                    if(flag)
                    dp[i][tarLen-1] = true;
                    else break;
                    flag = false;
                }else{
                    break;
                }
                i--;
            }
        }

        if(p[patLen-1] == '?' || p[patLen-1] == s[tarLen-1]){
            dp[patLen-1][tarLen-1] = true;
            int i = patLen-2;
            while(i >= 0){
                if(p[i] == '*'){
                    dp[i][tarLen-1] = true;
                }else{
                    break;
                }
                i--;
            }
        }

        for(int i = patLen-2; i>=0; i--){
            for(int j = tarLen-2; j >=0; j--){
                // cout<<i<<" "<<j<<endl;
                if(p[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }else if(p[i] == '*'){
                    if(dp[i+1][j+1] || dp[i][j+1] || dp[i+1][j]){
                            dp[i][j] = true;
                    }
                }else{
                    if(p[i] == s[j]){
                        dp[i][j] = dp[i+1][j+1];
                    }
                }
            }
        }

        // for(vector<bool> x : dp){
        //     for(bool y : x) cout<<y<<" ";
        //     cout<<endl;
        // }

        return dp[0][0];
    }
};