class Solution {
public:
    
    void dfs(int i , int j , vector<vector<int>> &vis , vector<vector<int>> &grid , int &cnt){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0) return ;
        
        
        vis[i][j] = 1;
        cnt++;
        
        dfs(i-1 , j , vis , grid , cnt);
        dfs(i , j+1 , vis , grid , cnt);
        dfs(i+1 , j , vis , grid , cnt);
        dfs(i , j-1 , vis , grid , cnt);
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        
        int cnt;
        int maxi = 0;
        
        for(int i=0 ;i<n ;i++){
            for(int j=0 ; j<m ;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    
                    cnt = 0;
                    dfs(i , j ,vis , grid , cnt);
                    
                    maxi = max(maxi , cnt);
                }
            }
        }
        
        return maxi;
    }
};