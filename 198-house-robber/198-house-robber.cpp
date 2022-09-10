class Solution {
public:
    
    int solve(vector<int> &ans, vector<int> &dp , int n){
        
        if(n==0) return dp[n]=ans[n];
        
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int left= ans[n] + solve(ans , dp , n-2);
        int right = 0+ solve(ans , dp , n-1);
        
        return dp[n]=max(left , right);
        
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        
        int ans=solve(nums , dp , n-1);
        
        return ans;
        
    }
};