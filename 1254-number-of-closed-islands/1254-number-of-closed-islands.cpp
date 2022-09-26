class Solution {
public:
    
    void dfs(int i , int j , vector<vector<int>> &vis , vector<vector<int>> &grid){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==1) return ;
        
        vis[i][j] = 1;
        
        dfs(i-1 , j , vis , grid);
        dfs(i , j+1 , vis , grid);
        dfs(i+1 , j , vis , grid);
        dfs(i , j-1 , vis , grid);
        
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        
        for(int j=0 ; j<m ;j++){
            if(!vis[0][j] && grid[0][j]==0){
                dfs(0 , j , vis , grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==0){
                dfs(n-1 , j , vis , grid);
            }
        }
        
        for(int i=0 ; i<n ;i++){
            if(!vis[i][0] && grid[i][0]==0){
                dfs(i , 0 , vis , grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==0){
                dfs(i , m-1 , vis , grid);
            }
        }
        
        int cnt =0 ;
        
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    dfs(i , j , vis , grid);
                }
            }
        }
        
        return cnt;
        
    }
};