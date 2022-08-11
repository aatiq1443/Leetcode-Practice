class Solution {
public:
   int countSubsets(vector<int>& nums,int sum){
        int n = nums.size();
        int dp[n+1][sum+1];
        for(int i = 0; i < n+1; i++)
            for(int j = 0; j < sum+1; j++){
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        for(int i = 1; i < n+1; i++)
            for(int j = 0; j < sum+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2==0){
            return countSubsets(nums,(sum+target)/2);
        }
        else{
            return 0;
        }
    }
};