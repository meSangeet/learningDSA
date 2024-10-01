
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);  // Memoization array initialized with -1
        return dp(n, memo);
    }
    
private:
    int dp(int n, vector<int>& memo) {
        // Base cases
        if (n <= 2) return n;
        
        // If already computed, return memoized result
        if (memo[n] != -1) return memo[n];
        
        // Compute and memoize the result
        memo[n] = dp(n-1, memo) + dp(n-2, memo);
        return memo[n];
    }
};