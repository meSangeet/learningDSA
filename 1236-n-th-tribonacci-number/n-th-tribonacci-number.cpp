class Solution {
public:
    int tribonacci(int n) {
        //tabulation start from base case and move till nth index
        vector<int> dp = {0,1,1};
        if(n < 3){
            return dp[n];
        }

        for(int i = 3; i<=n; i++){
            int cur = dp[i-1] + dp[i-2] + dp[i-3];
            dp.push_back(cur);
        }

        return dp.back();
    }
};