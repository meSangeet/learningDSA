class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        if(n <= 2) return n;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3 ; i<=n; i++){
            //we are at i = 3;

            int total = 0;
            total += dp[i-1]*2;

            for(int j = 2; j <= i-1; j++){
                int left = j-1;
                int right = i - j;
                total += dp[left]*dp[right];
            }

            dp[i] = total;
        }

        return dp.back();
    }
};