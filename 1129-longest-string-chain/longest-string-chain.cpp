class Solution {

    bool check(string str, string tar){
        int n = tar.length();
        if(str.length() != n-1) return false;

        bool flag = false;
        int ind = 0;
        for(int i = 0; i<n-1; i++){
            if(str[i] != tar[ind]){
                if(flag) return false;
                flag = true;
                ind++;
                if(str[i] != tar[ind]) return false;
            }
            ind++;
        }

        return true;
    }
public:
    static bool comp(string &a, string &b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(check(words[j],words[i])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        for(auto x : dp) cout<<x<<" ";
        return ans;
    }
};