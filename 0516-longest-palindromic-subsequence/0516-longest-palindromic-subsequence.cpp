class Solution {
public:
    
    int solve(string s1 , string s2 , int n , int m){
        
        int dp[1002][1002];
        
        for(int i=0 ; i<n+1 ; i++){
            for(int j= 0 ; j<m+1 ; j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        
        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<m+1 ; j++){
                
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int left = dp[i][j-1];
                    int right = dp[i-1][j];
                    
                    dp[i][j] = max(left , right);
                }
                
            }
        }
        return dp[n][m];
        
//         if(n ==0 || m == 0 ) return 0;
        
//         if(dp[n][m] != -1) return dp[n][m];
        
//         if(s1[n-1] == s2[m-1]) return 1 + solve(s1 , s2 , dp , n-1 , m-1);
//         else{
//             int left = solve(s1 , s2 , dp , n , m-1);
//             int right = solve(s1 , s2 , dp , n-1 , m);
            
//             return max(left , right);
//         }
    }
    
    
    int longestPalindromeSubseq(string s) {
        
        string s2 = s;
        reverse(s2.begin() , s2.end());
        
        int n = s.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1 ,vector<int>(m+1 , -1));
        return solve(s , s2 ,  n , m);
    }
};