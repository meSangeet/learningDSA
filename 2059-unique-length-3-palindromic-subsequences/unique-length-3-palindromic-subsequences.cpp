class Solution {
public:
    int countPalindromicSubsequence(string s) {
        deque<vector<int>> pre, post;
        vector<int> chars(26,0);
        int n = s.length();
        for(int i = 0; i<n; i++){
            int cc = s[i] - 'a';
            chars[cc]++;
            pre.push_back(chars);
        }
        vector<int> hars(26,0);
        for(int i = n-1; i>=0; i--){
            int cc = s[i] - 'a';
            hars[cc]++;
            post.push_front(hars);
        }
        int ans = 0;
        vector<vector<int>> dp(26, vector<int> (26, -1));
        for(int i = 1; i<=n-2; i++){
            for(int j = 0; j<26; j++){
                if(pre[i-1][j] && post[i+1][j]){
                    int fi = j;
                    int se = s[i] - 'a';
                    if(dp[fi][se] == -1){
                        ans++;
                        dp[fi][se] = 0;
                    }
                }
            }
        }

        return ans;
    }
};