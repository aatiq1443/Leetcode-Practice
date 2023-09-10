class Solution {
public:
    int countOrders(int n) {
         long base = 1000000007;
        if (n == 1)
        {
            return 1;
        }
        long res = 1;
        for (int i = 2; i <= n; ++i)
        {
            res = ((((long)res*(2*i-1))%base)*i)%base;
        }

        return res;
    }
};