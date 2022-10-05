class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1; 
        
        if(n==10) return 10;
        
        int dp[n+1];
        
        dp[0] = 1;
        dp[1] = 10;
        
        long long int digit = 9;
        
        for(int i=2; i<=n ;i++){
            digit = digit * (9 - (i - 2));
            
            dp[i] = digit;
            
            dp[i] = dp[i]+ dp[i-1];
        }
        
        return dp[n];
    }
};

