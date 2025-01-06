#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;  
        vector<vector<int>> dp(305, vector<int> (305, -1));  
        vector<vector<int>> mx(305, vector<int> (305, -1));  

        for (auto num : nums) {
            if (dp[num][0] < 1) dp[num][0] = 1;

            for (int prev = 1; prev <= 300; prev++) {
                int currDiff = abs(num - prev); 
                int mxLen = mx[prev][currDiff];  

                if (mxLen > 1) {
                    dp[num][currDiff] = max(dp[num][currDiff], 1 + mxLen); 
                } else {
                    if (mx[prev][0] > 0) {
                        dp[num][currDiff] = max(dp[num][currDiff], 2); 
                    }
                }

                ans = max(ans, dp[num][currDiff]);  
            }

            mx[num][299] = dp[num][299];
            for (int i = 298; i >= 0; i--) {
                mx[num][i] = max(dp[num][i], mx[num][i + 1]);  
            }
        }

        return ans;  
    }
};
