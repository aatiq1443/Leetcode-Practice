class Solution {
public:
    int helper(vector<int>& piles, int m, int startIndex, int sum, vector<vector<int>>& dp) {
        int n = piles.size();
        if(startIndex>=n) {
            return 0;
        }
        if(dp[m][startIndex] != -1) {
            return dp[m][startIndex];
        }
        int maxStones = 0;
        int cumulativeSum = 0;
        for(int x = 1; x<=2*m; x++) {
            int index = startIndex + x - 1;
            if(index>=n) {
                break;
            }
            cumulativeSum += piles[index];
            maxStones = max(sum - helper(piles, max(m,x), startIndex+x, sum - cumulativeSum, dp), maxStones);
        }
        return dp[m][startIndex] = maxStones;
    }
    int stoneGameII(vector<int>& piles) {
        int m = 1, n = piles.size(), startIndex = 0;
        int totalStones = 0;
        for(int i=0;i<n;i++) {
            totalStones += piles[i];
        }
        vector<vector<int>> dp(2*n, vector<int>(n,-1));
        return helper(piles,m,startIndex,totalStones,dp);
    }
};