class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.length() , n = s2.length();
        
        int c1 = 0, c2=0;
        
        for(char c:s1)
            
            c1+=c;
        for(char c:s2)
            c2+=c;
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = s1[i-1]+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        int lcs = dp[m][n];
        return c1-lcs+c2-lcs; 
        
    }
};