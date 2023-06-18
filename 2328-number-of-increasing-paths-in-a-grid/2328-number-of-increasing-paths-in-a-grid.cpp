class Solution {
public:
   int n, m;
const int MOD = 1e9+7;

vector<pair<int, int> > dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int> > dp;

int dfs(vector<vector<int>>& G, int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    int cnt = 1;
    for (auto x : dir) {
        int ni = i + x.first, nj = j + x.second;

        if (ni >= 0 && nj >= 0 && ni < n && nj < m && G[ni][nj] > G[i][j]) {
            cnt = (cnt % MOD + dfs(G, ni, nj) % MOD) % MOD;
        }
    }

    return dp[i][j] = cnt;
}

int countPaths(vector<vector<int>>& G) {
    n = G.size(), m = G[0].size();

    dp.resize(n, vector<int> (m, -1));

	int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = (ans % MOD + dfs(G, i, j) % MOD) % MOD;
        }
    }

    return ans;
}
};