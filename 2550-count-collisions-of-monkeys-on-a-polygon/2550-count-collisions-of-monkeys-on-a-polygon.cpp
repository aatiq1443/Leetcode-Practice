class Solution {
public:
    int M = 1e9 + 7;
    int exponential(int a, int b) {
		int ans = 1;
		while(b) {
			if(b&1) ans = (ans * 1LL * a) % M;
			a = (a * 1LL * a) % M;
			b >>= 1;
		}
		return ans;
	}

    int monkeyMove(int n) {
        return (exponential(2, n) - 2 + M) % M;
    }
};