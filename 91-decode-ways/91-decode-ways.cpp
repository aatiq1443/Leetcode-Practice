class Solution {
public:
    
    int numDecodings(string s) {
        
        int n=s.length();
        vector<int>dp(n,-1);
        helper(s, 0,dp);  
        return dp[0];
    }
    
    
    int helper(string str, int index, vector<int>&dp){
     
        if(index==str.length() )   
            return 1;
        
        if(dp[index]!=-1)
            return dp[index];
        
        string c;
        int count=0;
        for(int i=index;i<str.length();i++){
            c=c+str[i];
            int a=stoi(c);
            if(a>=1 && a<=26){  
                count+=helper(str, i+1, dp);
            }
            else
                break;
             
        }
        dp[index]=count;
        
        return dp[index];
    }
};
