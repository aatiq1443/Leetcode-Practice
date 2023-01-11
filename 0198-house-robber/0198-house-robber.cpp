class Solution {
public:
    
    int solve(vector<int>&nums , int n , vector<int> &dp){
        
        dp[0] = nums[0];
        
        for(int i=1 ; i<n ;i++){
            int first = nums[i] ;
            if(i>1) first+=dp[i-2];
            
            int second = 0 + dp[i-1];
            
            dp[i] = max(first , second);
        }
        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , 0);
        return solve(nums , nums.size() , dp);
    }
};

