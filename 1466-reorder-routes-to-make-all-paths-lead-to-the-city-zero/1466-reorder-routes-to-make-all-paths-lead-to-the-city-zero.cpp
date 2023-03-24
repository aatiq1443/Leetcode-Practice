class Solution {
public:
    void dfs(vector<vector<int>> & gr, vector<vector<int>> & gr2, vector<bool> &vis, int s, int &ans, queue<int> &q)
    {
        if(vis[s]) return;
        vis[s] = true;

        for(int adj: gr2[s])
        {
            q.push(adj);
        }

        for(int e:gr[s])
        {
            if(!vis[e])
            {
                ans++;
                dfs(gr, gr2, vis, e, ans, q);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> gr(n);
        vector<vector<int>> gr2(n);

        for(auto v:connections)
        {
            gr[v[0]].push_back(v[1]);
            gr2[v[1]].push_back(v[0]);
        }

        queue<int> q;
        q.push(0);

        while(q.size())
        {
            int x = q.front();
            q.pop();
            dfs(gr, gr2, vis, x, ans, q);
        }
         return ans;
    }
};