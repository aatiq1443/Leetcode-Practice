class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi = INT_MAX;
        int profit = -1;
        
        for(int i=0 ;i<prices.size() ;i++){
            if(maxi>prices[i]) maxi= prices[i];
            
            profit= max(profit , abs(maxi - prices[i]));
        }
        
        return profit;
    }
};