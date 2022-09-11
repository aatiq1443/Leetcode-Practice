class Solution {
public:
    int solve(vector<int> & ans , int n , vector<int>&dp){
         
        dp[0]=ans[0];
        
        for(int i=1;i<n;i++){
            int left = ans[i] ;
            if(i>1) left+=dp[i-2];
            int right = 0 + dp[i-1];
            
            dp[i]=max(left , right);
        }
        return dp[n-1];
        
//         int left = ans[n] + solve(ans , n-2 ,dp);
        
//         int right =0 + solve(ans , n-1  ,dp);
        
//         return dp[n]=max(left , right);
    }
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
       
        if(n==1) return nums[0];
        
        vector<int> temp1 , temp2;
        
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        
       int size1= temp1.size();
        int size2= temp2.size();
        
        vector<int>dp(n+1 , -1);
        
        return max(solve(temp1 , size1 , dp)   , solve( temp2 , size2 , dp));
    }
};