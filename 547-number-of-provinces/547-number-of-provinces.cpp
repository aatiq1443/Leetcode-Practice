class Solution {
public:
    
    void dfs(int i , vector<int> adj[] , vector<int>&vis){
        
        vis[i] =1 ;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<int> adj[n];
        
        for(int i= 0 ;i<n;i++){   
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);  
                }
            }
        }
        
        vector<int> vis(n , 0);
        int cnt=0;
        for(int i=0; i<n ;i++){
            if(!vis[i]){
                cnt++;
                dfs(i , adj , vis);
            }
        }
        
        return cnt;
   
    }
};