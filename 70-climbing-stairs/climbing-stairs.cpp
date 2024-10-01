
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        vector<int> dp(n+1);
        dp[1] = 1;  // Base case: 1 way to climb 1 step
        dp[2] = 2;  // Base case: 2 ways to climb 2 steps
        
        // Build the solution bottom-up
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};