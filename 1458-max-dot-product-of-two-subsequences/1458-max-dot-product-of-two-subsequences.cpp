class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -10)); 

        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j <= m; j++) {
                
                dp[i][j] = max((long long)nums1[i - 1] * nums2[j - 1], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};