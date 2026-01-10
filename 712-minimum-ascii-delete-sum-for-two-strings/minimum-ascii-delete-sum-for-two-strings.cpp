class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MAX));

        dp[n1][n2] = 0;

        for(int i = n1 - 1; i >= 0; i--) {
            dp[i][n2] = dp[i+1][n2] + s1[i];
        }

        for(int j = n2 - 1; j >= 0; j--) {
            dp[n1][j] = dp[n1][j+1] + s2[j];
        }

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                // try moving i 
                dp[i][j] = min(dp[i][j] , s1[i] + dp[i+1][j]);

                // try moving j
                dp[i][j] = min(dp[i][j] , s2[j] + dp[i][j+1]);

                // try moving both by deleting 
                dp[i][j] = min(dp[i][j],  s1[i] + s2[j] + dp[i+1][j+1]);

                // if equal then just move forward
                if(s1[i]==s2[j]) dp[i][j] = min(dp[i][j] , dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};