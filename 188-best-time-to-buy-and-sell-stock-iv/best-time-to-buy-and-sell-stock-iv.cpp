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
        
        vector<int> buy(k+1, INT_MIN);
        vector<int> sell(k+1, 0);
        
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i-1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        
        return sell[k];
    }
};