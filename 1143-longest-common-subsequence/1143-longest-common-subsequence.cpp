class Solution {
public:
    
    int solve(string &str1 , string &str2 , int n , int m , vector<vector<int>> &dp){
        
        if(n==0 || m==0) return 0;
        
        if(dp[n][m] != -1 ) return dp[n][m];
        
        if(str1[n-1] == str2[m-1]) {
            
            return dp[n][m] = 1 + solve(str1 , str2 , n-1 , m-1 , dp);
        }   

        else{
            int left = solve(str1 , str2 , n , m-1 , dp);
            int right = solve(str1 , str2 , n-1 , m , dp);
            
            return dp[n][m] = max(left , right);
        }
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));
        
        
        
        return solve(text1 , text2 , n , m , dp);
        
    }
};