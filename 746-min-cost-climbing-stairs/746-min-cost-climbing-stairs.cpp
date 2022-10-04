class Solution {
public:
    
//      int solve(vector<int> &cost , int n , vector<int> &dp){
//         if(n<=1) return cost[n];
        
//         if(dp[n]!=-1) return dp[n];
        
//         int first = solve(cost , n-1 , dp) + cost[n];
      
       
//         int  second =solve(cost , n-2 ,dp) + cost[n];
        
//         return dp[n]=min(first , second);
//     }
    
//     int minCostClimbingStairs(vector<int>& cost) {
        
//         int n = cost.size();
//         vector<int> dp(n+1 , 0);
        
//         return min(solve(cost , cost.size()-1 , dp) , solve(cost , cost.size()-2 , dp));
//     }
    
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n+1 , 0);
        
        for(int i=2 ;i<=n ;i++){
            int first = dp[i-1] + cost[i-1];
            int second = dp[i-2] + cost[i-2];
            
            dp[i] = min(first , second);
        }
        
        return dp[n];
    }
};