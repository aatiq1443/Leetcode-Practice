class Solution {
public:
    
    void dfs(int i , vector<vector<int>> &adj , vector<int>&vis){
        
        vis[i] = 1 ;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& mat) {
        
        if( n > mat.size()+1) return -1;
        
        vector<vector<int>> adj(n);
        
        for(auto i:mat){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> vis(n , 0);
        
        int cnt =-1;
        
        for(int i=0;i<n ;i++){
            if(!vis[i]){
                cnt++;
                dfs(i , adj ,vis);
            }
        }
        return cnt;
        
    }
};
