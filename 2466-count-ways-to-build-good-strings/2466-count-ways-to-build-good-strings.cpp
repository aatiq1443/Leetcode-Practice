class Solution {
    int mod = 1000000007;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        std::vector<int> dp(high + std::max(zero, one), 0);

        dp[high]  = 1;

        for(int i = high-1; i >= 0; --i) {
            int takeOne = dp[i + one];
            int takeZero = dp[i + zero];
            dp[i] = ((takeOne + takeZero) + (i >= low)) % mod;
        }

        return dp[0];
    }
};