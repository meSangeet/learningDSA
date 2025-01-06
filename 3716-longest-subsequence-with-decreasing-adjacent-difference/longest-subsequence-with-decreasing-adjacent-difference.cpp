class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;  
        vector<vector<int>> dp(310, vector<int> (305, -1));  
        vector<vector<int>> maxSubseq(310, vector<int> (305, -1));  

        for (auto currentNum : nums) {
            if (dp[currentNum][0] < 1) dp[currentNum][0] = 1;

            for (int prevNum = 1; prevNum <= 305; prevNum++) {
                int diff = abs(currentNum - prevNum); 
                int prevMaxLen = maxSubseq[prevNum][diff];  

                if (prevMaxLen > 1) {
                    dp[currentNum][diff] = max(dp[currentNum][diff], 1 + prevMaxLen); 
                } else {
                    if (maxSubseq[prevNum][0] > 0) {
                        dp[currentNum][diff] = max(dp[currentNum][diff], 2); 
                    }
                }

                maxLength = max(maxLength, dp[currentNum][diff]);  
            }

            maxSubseq[currentNum][302] = dp[currentNum][302];
            for (int i = 301; i >= 0; i--) {
                maxSubseq[currentNum][i] = max(dp[currentNum][i], maxSubseq[currentNum][i + 1]);  
            }
        }

        return maxLength;  
    }
};
