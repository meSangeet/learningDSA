class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int mlis = 1;
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2,1));
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] > a[j]) {
                    if (1 + dp[j][0] > dp[i][0]) {
                        dp[i][0] = 1 + dp[j][0];
                        dp[i][1] = dp[j][1];
                    } else if (1 + dp[j][0] == dp[i][0]){
                        dp[i][1] += dp[j][1];
                    }
                }
            }
        }
        map<int,int> m;
        int freq = 0;
        for(auto x : dp){
            m[x[0]] += x[1];
        }
        for(auto x : m){
            freq = x.second;
        }
        return freq;
    }
};