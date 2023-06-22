class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
         if (prices.size() < 2)
            return 0;
			
        int profit = 0, min = prices[0];
        
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] - fee > min)
            {
                profit += prices[i] - fee - min;
                min = prices[i] - fee;
            }
        }
        
        return profit;
    }
};