class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi = INT_MAX;
        int ans = -1;
        
        for(int i=0 ; i< prices.size() ; i++){
            maxi = min(maxi , prices[i]);
            
            ans = max(ans  ,  abs(prices[i] - maxi));
        }
        return ans;
    }
};