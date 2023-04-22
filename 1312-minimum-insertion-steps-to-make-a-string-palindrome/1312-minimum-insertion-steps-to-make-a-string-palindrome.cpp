class Solution {
public:
    bool isPal(string s)
    {
        if(s.size() <= 1)
            return 1;
        for(int i = 0, j = s.size() - 1; i < j; i++,j--)
        {
            if(s[i] != s[j])
                return 0;
        }
        return 1;
    }
    vector<vector<int>> dp;
    int f(string &s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
        {
            dp[i][j] = f(s, i + 1, j - 1);   
        }
        else
            dp[i][j] = min(f(s, i , j - 1), f(s, i + 1, j)) + 1;
        
        return dp[i][j];
    }
    
    int minInsertions(string s) {
        if(isPal(s))
            return 0;
        int n = s.size();
        int i = 0, j = n - 1;
        dp = vector<vector<int>> (n, vector<int>(n, - 1));
        return f(s, i, j);
    }
};