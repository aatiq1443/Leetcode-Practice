class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        
        if(grid[0][0] == 1) return -1;
        if(n==1 && m==1) return 1;
        if(grid[n-1][m-1]==1) return -1;
        
        queue<pair<pair<int , int> ,int>>q;
        
        vector<vector<int>> vis(n , vector<int>(m ,0));
        
        q.push({{0 , 0 } , 1});
    
        vis[0][0] = 1;
        int time;
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
             time = q.front().second;
            q.pop();
         
            
            for(int delrow=-1 ; delrow<=1 ; delrow++){
                for(int delcol = -1 ; delcol<=1 ; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol] == 0){
                        if(nrow==n-1 && ncol == m-1) return time+1;
                        vis[nrow][ncol] = 1;
                        q.push({{nrow , ncol} , time+1});
                    }
                }
            }
            
        }
         return -1;
    }
};