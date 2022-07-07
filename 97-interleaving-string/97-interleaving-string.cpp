class Solution {
public:
     
    int solve(int l1,int l2,int l3,string s1, string s2, string s3,  vector<vector<int>>&dp){
        
        if(l3==-1 && l1 ==-1 && l2==-1) return 1;
        if(l3<0) return 0;
        
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) return dp[l1][l2];
        
        if(l1>=0 && l2>=0 && s1[l1]==s3[l3] && s2[l2]== s3[l3]){
            
            return dp[l1][l2]= (solve(l1-1,l2,l3-1,s1,s2,s3,dp) || solve(l1,l2-1,l3-1,s1,s2,s3,dp));
        }
        else if(l1>=0 && s1[l1]==s3[l3]){
          return solve(l1-1,l2,l3-1,s1,s2,s3,dp);  
            
        }
        else if(l2>=0 && s2[l2]==s3[l3]){
            return solve(l1,l2-1,l3-1,s1,s2,s3,dp);
        }      
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1.size()-1,s2.size()-1,s3.size()-1,s1,s2,s3,dp);     
    }
};