class Solution {
public:
    
   void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j ,int val , int color , int m , int n)
    {
	
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]!=val)
            return;
        vis[i][j] = true;
		
        if(i==0 || j==0 || i>=m-1 || j>=n-1)
            grid[i][j]=color;
			
        if((i+1<=m-1 && grid[i+1][j]!=val && !vis[i+1][j]) || (i-1>=0 && grid[i-1][j]!=val && !vis[i-1][j]) || (j+1<=n-1 && grid[i][j+1]!=val && !vis[i][j+1]) || (j-1>=0 && grid[i][j-1]!=val && !vis[i][j-1]))
            grid[i][j] = color;
			
        dfs(grid , vis , i+1 , j ,val , color , m , n);
        dfs(grid , vis , i , j+1 ,val , color, m , n);
        dfs(grid , vis , i , j-1 ,val , color, m , n);
        dfs(grid , vis , i-1 , j ,val , color, m , n);
        return;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n , vector<bool>(m,false));
        
        dfs(grid,vis,row,col,grid[row][col] , color , n ,m);
        return grid;
    }
};