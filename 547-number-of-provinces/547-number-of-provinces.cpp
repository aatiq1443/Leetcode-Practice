class Solution {
public:
    
    void bfs(int node , vector<vector<int>>&grid , vector<int>&vis  , vector<int> adj[]){
        
        vis[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(auto i:adj[temp]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m =grid[0].size();
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(n,0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                bfs(i , grid , vis , adj);
            }
        }
        
        return cnt;
    }
};