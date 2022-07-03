class Solution {
public:
    int maxProfit(vector<int>& price) {
        int maxi=INT_MAX;
        int n=price.size();
        int profit=0;
        for(int i=0;i<n;i++){
            maxi=min(maxi,price[i]);
            profit=max(profit, (price[i]-maxi));
        }
        return profit;
    }
};