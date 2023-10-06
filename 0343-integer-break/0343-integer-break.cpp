class Solution {
public:
    int integerBreak(int n) {
         if (n <= 3) return 1 * (n - 1);
        int res = 1;
        while (n >= 5) n -= 3, res *= 3;
        return res * n;
    }
};