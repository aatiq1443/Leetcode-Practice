class Solution {
public:
    void dfs(int i , int j , vector<vector<int>> &vis , vector<vector<int>> &mat){
        
        if(i<0 || i>= mat.size() || j<0 || j>=mat[0].size() || vis[i][j]==1 || mat[i][j]==0) return ;
        
        vis[i][j] = 1;
        
        dfs(i-1 , j , vis , mat);
        dfs(i , j+1 , vis , mat);
        dfs(i+1 , j , vis , mat);
        dfs(i , j-1 , vis , mat);
        
    }
    
    
    int numEnclaves(vector<vector<int>>& mat) {
        
         int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m ,0));
        
        // traverse the first and last row simultaneously
        
        // too traverse the first and last row we need to traverse on the column part
        
        for(int j=0 ;j< m;j++){
             
            // first row
            if(!vis[0][j] && mat[0][j] == 1){
                dfs(0 , j , vis , mat);
            }
            
            // last row
            if(!vis[n-1][j] && mat[n-1][j] == 1){
                dfs(n-1 , j , vis , mat);
            }
        }
        
         // traverse the first and last col simultaneously
        
        // too traverse the first and last col we need to traverse on the row part
        
        
        for(int i=0 ;i< n;i++){
             
            // first col
            if(!vis[i][0] && mat[i][0] == 1){
                dfs(i , 0 , vis , mat);
            }
            
            // last col
            if(!vis[i][m-1] && mat[i][m-1] == 1){
                dfs(i , m-1 , vis , mat);
            }
        }
        
        
        // traverse on the main matrix which will checks whether any 'O' surrounded by X or not if yes then mark 'O' as 'X'
        int cnt=0;
        for(int i=0 ; i< n;i++){
            for(int j=0; j<m;j++){
                if(!vis[i][j] && mat[i][j]==1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};