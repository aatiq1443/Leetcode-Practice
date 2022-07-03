class Solution {
    private:
    int solve( vector<int> &dp , int n ){
        if(n==0  || n==1){
            return 1;
        }
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int first=solve(dp , n-1);
        int second = solve(dp , n-2);
        dp[n]=first+second;
        return dp[n];
    }
public:
    int climbStairs(int n) {
       
        vector<int> dp(n+1,-1);
        int ans=    solve(dp,n);
        return ans;
    }
};