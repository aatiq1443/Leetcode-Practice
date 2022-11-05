class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        while (n) {
            if (n % 2) ans = n > 0 ? ans * x : ans / x;
            x = x * x;
            n /= 2;
        }
        return ans;
    }
};