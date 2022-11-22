class Solution {
public:
     int solve(int n , vector<int> &dp){
        
        dp[0] = 0;
        
        for(int i=1 ; i<=n ;i++){
            for(int j=1 ; j<=sqrt(n); j++){
                if(i-(j*j)>=0)
                dp[i] = min(dp[i] , 1+dp[i - j*j]);
            }
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        
        vector<int> dp(n+1 , INT_MAX);
        return solve(n , dp);
    }
};