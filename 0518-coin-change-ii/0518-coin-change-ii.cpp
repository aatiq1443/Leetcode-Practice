class Solution {
public:
    
    int change(int target, vector<int>& nums) {
        
         int n=nums.size();
        
        vector<double> dp(target+1);
        
        dp[0]=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=nums[i];j<=target;j++)
                dp[j]+=dp[j-nums[i]];
        }
        
        return dp[target];
    }
};