class Solution {
public:
    
    bool dfs(int src , vector<vector<int>> &graph , int color[]){
        
        queue<int>q;
        q.push(src);
        
        color[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto child:graph[node]){
                if(color[child] == -1){
                    color[child] = !color[node];
                    q.push(child);
                }
                else if(color[child] == color[node]) return false;
            }
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n =graph.size();
        int color[n];
        
        for(int i=0;i<n;i++) color[i] = -1;
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i , graph , color) == false) return false;
            }
        }
        
        return true;
        
    }
};