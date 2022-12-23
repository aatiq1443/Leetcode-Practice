class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n < 2) return 0;
        
        int dp[n];
        memset(dp, 0, sizeof(dp));
        
        dp[1] = max(0, prices[1] - prices[0]);
        int local_max = max(-prices[0], -prices[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], prices[i] + local_max);
            local_max = max(local_max, dp[i-2] - prices[i]);
        }
        
        return dp[n-1];
    }
};