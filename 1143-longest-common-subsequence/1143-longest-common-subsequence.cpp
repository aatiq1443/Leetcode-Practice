class Solution {
public:
    
//     int solve(string &str1 , string &str2 , int n , int m , vector<vector<int>> &dp){
        
//         if(n==0 || m==0) return 0;
        
//         if(dp[n][m] != -1 ) return dp[n][m];
        
//         if(str1[n-1] == str2[m-1]) {
            
//             return dp[n][m] = 1 + solve(str1 , str2 , n-1 , m-1 , dp);
//         }   

//         else{
//             int left = solve(str1 , str2 , n , m-1 , dp);
//             int right = solve(str1 , str2 , n-1 , m , dp);
            
//             return dp[n][m] = max(left , right);
//         }
        
//     }
    
    int tab( string str1 , string str2 , int n , int m ){
        
        int dp[1002][1002];
        
        for(int i=0 ; i< n+1 ;i++){
            for(int j=0 ; j< m+1 ;j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }
        
        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<m+1 ; j++){
                
                if(str1[i-1] == str2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                
                else{
                    int left = dp[i][j-1];
                    int right = dp[i-1][j];
                    
                    dp[i][j] = max(left , right);
                }
            }
        }
        
        
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        return tab(text1 , text2 , n , m );
        
      
    }
};
























