class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int buy = INT_MIN;  // Maximum profit if we've just bought or are ready to buy
        int sell = 0;       // Maximum profit if we've just sold or are in cooldown
        int prevSell = 0;   // Previous day's sell profit
        
        for (int price : prices) {
            int tempBuy = buy;
            buy = max(buy, prevSell - price);
            prevSell = sell;
            sell = max(sell, tempBuy + price);
        }
        
        return sell;
    }
};