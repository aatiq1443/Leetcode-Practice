class Solution {
public:
    int solve(vector<int> &ans , int i , int sum){
        if(i==ans.size()){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        int left=solve(ans, i+1, sum+ans[i]);
        int right=solve(ans, i+1, sum-ans[i]);
        
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        return solve(nums, 0, target );
    }
};