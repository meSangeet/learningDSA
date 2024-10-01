class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;
        
        if (k >= n/2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    maxProfit += prices[i] - prices[i-1];
                }
            }
            return maxProfit;
        }
        
        vector<int> states(2*k+1, INT_MIN);
        states[0] = 0;
        
        for (int price : prices) {
            for (int i = 0; i < 2*k; i += 2) {
                states[i+1] = max(states[i+1], states[i] - price);
                states[i+2] = max(states[i+2], states[i+1] + price);
            }
        }
        
        return *max_element(states.begin(), states.end());
    }
};