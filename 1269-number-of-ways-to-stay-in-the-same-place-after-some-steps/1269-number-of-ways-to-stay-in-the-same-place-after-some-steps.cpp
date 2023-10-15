class Solution {
public:
    int MOD = 1e9 + 7;
    int solveMem(int steps, int arrLen, int idx, vector<vector<long long int>> &dp) {
        if(idx < 0 || idx >= arrLen || steps < 0) return 0;

        if(idx == 0 && steps == 0) return 1;

        if(dp[steps][idx] != -1) return dp[steps][idx];

        long long int left = solveMem(steps - 1, arrLen, idx - 1, dp) % MOD;
        long long int right = solveMem(steps - 1, arrLen, idx + 1, dp) % MOD;
        long long int stay = solveMem(steps - 1, arrLen, idx, dp) % MOD;

        return dp[steps][idx] = (left + stay + right) % MOD;
    }
    int numWays(int steps, int arrLen) {
        if(arrLen > steps) arrLen = steps;
        vector<vector<long long int>> dp(steps + 1, vector<long long int>(arrLen, -1));
        return solveMem(steps, arrLen, 0, dp);
    }
};