class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) {
            return 1.0;
        }
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0;
        double result = 0.0;

        for (int i = 1; i <= n; ++i) {
            // The probability of reaching score 'i' is the sum of probabilities
            // of scores in the window [i - maxPts, i - 1], divided by maxPts.
            // This sum is exactly what 'windowSum' represents.
            dp[i] = windowSum / maxPts;

            // If the current score 'i' is less than k, we must draw again.
            // Therefore, the probability of being at score 'i' (dp[i])
            // contributes to the window sum for calculating future probabilities.
            if (i < k) {
                windowSum += dp[i];
            } 
            // If the current score 'i' is k or greater, we stop drawing.
            // This is a valid terminal state, so we add its probability to our final result.
            else {
                result += dp[i];
            }

            // Now, we slide the window forward. We need to remove the probability
            // of the score that just fell out of the window's left side, which is (i - maxPts).
            if (i >= maxPts) {
                if (i - maxPts < k) {
                   windowSum -= dp[i - maxPts];
                }
            }
        }

        return result;
    }
};
