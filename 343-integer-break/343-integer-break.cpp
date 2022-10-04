class Solution {
public:
    
    int solve(int n , vector<int> &dp){
        if(n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans = 0;
        for(int i=1 ; i<n ;i++){
             int prod= i* max(n-i , solve(n-i , dp));
             if(prod > ans) ans=prod;
            
        }
        
        return dp[n]=ans;
    }
    
    int integerBreak(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n , dp);
    }
};