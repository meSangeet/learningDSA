class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        //looks like a dp problem
        //dp[i] -> length of lis ending at ith index
        int n = a.size();
        vector<int> dp(n,1);
        int ans = 1;
        for(int i = 1; i<n; i++){
            //now we will go to the past indices to see if they are valid
            for(int j = i-1; j>=0; j--){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};