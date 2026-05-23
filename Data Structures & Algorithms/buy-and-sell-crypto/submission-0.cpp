class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int price : prices)
        {
            minPrice  = std::min(price, minPrice);
            maxProfit = std::max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
