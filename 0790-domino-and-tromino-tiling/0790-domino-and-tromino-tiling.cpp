class Solution {
public:
    int numTilings(int N) {
        
        int mod = 1000000007;
        int dp[N+1][2];
        
        dp[0][1] = 1, dp[0][0] = 0;
        dp[1][1] = 1, dp[1][0] = 0;
        
        for(int i=2; i<N+1; i++){
            
            dp[i][1] = ((dp[i-1][1] + dp[i-2][1])%mod + (dp[i-1][0])%mod)%mod;
            dp[i][0] = ((dp[i-2][1]*2)%mod + (dp[i-1][0])%mod)%mod;
            
        }
        
        return dp[N][1];
    }
};