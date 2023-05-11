class Solution {
public:
     int BottomUpDP(vector<int>& A, vector<int>& B,int n,int m){
         
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                A[i-1]==B[j-1]?dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 ):dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
         
        return dp[n][m];
         
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int n = A.size(),m = B.size();
        
        return BottomUpDP(A,B,n,m);
    }
};