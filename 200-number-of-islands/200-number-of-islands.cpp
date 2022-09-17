class Solution {
public:
    
    void bfs(int row, int col , vector<vector<int>> &vis , vector <vector<char>> &grid){
        
        int n= grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        
        queue<pair<int ,int>>q;
        q.push({row , col});
        
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            
            for(int del_row =-1 ; del_row<=1 ;del_row++){
                for(int del_col=-1 ; del_col<=1 ;del_col++){
                    int nrow = row+del_row;
                    int ncol = col+del_col;
                     if((del_row==-1&&del_col==-1) || (del_row==-1&&del_col==1) || (del_row==1&&del_col==-1) || (del_row==1&&del_col==1)){
                        continue;
                    }
                    if(nrow >=0 && nrow< n && ncol>=0 && ncol <m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow , ncol});
                    }
                }
            }
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m , 0));
        
        int cnt = 0;
        
        for(int row=0 ;row<n ;row++){
            for(int col = 0; col<m ;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row , col ,vis , grid);
                }
            }
        }
        
        return cnt;
    }
};