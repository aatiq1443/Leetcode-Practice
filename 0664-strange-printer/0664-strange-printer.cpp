class Solution {
public:
     int f(int i, int j, string &s,  vector<vector<int>> &dp)
    {
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int x=i;x<j;x++)
        {
            ans=min(ans, f(i,x, s, dp)+f(x+1, j,s, dp));
        }
        return dp[i][j]=(s[i]==s[j])?ans-1: ans;
    }
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, n-1, s, dp);
    }
};