class Solution {
public:
     bool solve(int s,int &n,vector<int> &v,vector<int> &dp){
        if(s>=n){
            return true;
        }
        if(dp[s]!=-1)return dp[s];
        bool ans = false;
        if(s+1<n&&v[s]==v[s+1]){
            ans |= solve(s+2,n,v,dp);
        }
        if(s+2<n&&v[s]==v[s+1]&&v[s+1]==v[s+2]){
            ans |= solve(s+3,n,v,dp);
        }
        if(s+2<n&&v[s]+1==v[s+1]&&v[s+1]+1==v[s+2]){
            ans |= solve(s+3,n,v,dp);
        }
        return dp[s] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};