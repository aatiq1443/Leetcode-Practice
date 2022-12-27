class Solution {
public:
    
    int nl;
    vector<int> ans, cnt, g[30005];
        
    void dfs(int u, int p) {
        
        for(auto v: g[u]) {
            
            if(v == p) continue;
            dfs(v, u);
            cnt[u] += cnt[v];
            ans[u] += ans[v] + cnt[v];
            
        }
        
        cnt[u] += 1;
    }

    void dfs2(int u, int p) {
        
        for(auto v: g[u]) {
            
            if(v == p) continue;
            ans[v] = ans[u] - cnt[v] + nl - cnt[v];
            dfs2(v, u);
            
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        nl = n;
        ans.resize(n);
        cnt.resize(n);
        
        for(auto x: edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};