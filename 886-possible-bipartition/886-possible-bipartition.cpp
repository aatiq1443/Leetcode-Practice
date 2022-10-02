class Solution {
public:
      bool solve(int src, int color[], vector<int> adj[]){
        
        if(color[src] == -1){
            color[src] = 1;
        }
        
        for(auto i: adj[src]){
            
            if(color[i] == -1){
                color[i] = 1 - color[src];
                if(solve(i, color, adj) == false){
                    return false;
                }
            
            }else if(color[i] == color[src]){
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int color[n+1];
        
        for(int i=0 ;i<=n ;i++) color[i] = -1;
        
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!solve(i, color, adj)){
                    return false;
                }
            }
        }
        return true;
        
    }
};