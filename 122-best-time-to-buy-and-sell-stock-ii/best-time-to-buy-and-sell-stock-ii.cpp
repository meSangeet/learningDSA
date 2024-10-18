class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int totalProfit = 0;
        int n = prices.size();
        
        for (int i = 1; i < n; ++i) {
            // If the price today is greater than the price yesterday
            if (prices[i] > prices[i - 1]) {
                // Add the difference to total profit
                totalProfit += (prices[i] - prices[i - 1]);
            }
        }
        
        return totalProfit;
    }
};