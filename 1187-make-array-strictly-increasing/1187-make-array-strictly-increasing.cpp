class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
         sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        
        int n = arr1.size();
        int m = arr2.size();
        
        vector<vector<int>> dp (n+1, vector<int>(m+1));
        
        dp[0][0] = 0;
        
        for (int j = 1; j <= m; ++j) dp[0][j] = 2*n;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 2*n;
            if (i == 1 || arr1[i-1] > arr1[i-2]) dp[i][0] = dp[i-1][0];
            int cur_min = 2*n;
            
            for (int j = 1; j <= m; ++j) {
                
                if (i == 1 || arr1[i-1] > arr2[j-1])
                    dp[i][0] = min(dp[i][0], dp[i-1][j]);
                dp[i][j] = cur_min + 1;
                if (i == 1 || arr2[j-1] > arr1[i-2]) dp[i][j] = min(dp[i][j], dp[i-1][0] + 1);
                cur_min = min(cur_min, dp[i-1][j]);
            }
        }
        
        int ans = 2*n;
        for (int j = 0; j <= m; ++j) {
            ans = min(ans, dp[n][j]);
        }
        
        return (ans > n) ? -1 : ans;
    }
};