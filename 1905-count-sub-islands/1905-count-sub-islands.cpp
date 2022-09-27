class Solution {
public:
    
    void dfs(int i , int j , vector<vector<int>> &vis2 , vector<vector<int>> &grid1 , vector<vector<int>> &grid2 , int &ans ){
        
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || vis2[i][j]==1 || grid2[i][j]==0) return ;
        
        if(grid1[i][j]==0) ans =0;
        vis2[i][j] =1;
        
        
        dfs(i-1 , j , vis2 , grid1 , grid2 , ans);
        dfs(i , j+1 , vis2 , grid1 , grid2 , ans);
        dfs(i+1 , j , vis2 , grid1 , grid2 , ans);
        dfs(i , j-1 , vis2 , grid1 , grid2 , ans);
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n1 = grid1.size();
        int m1 = grid1[0].size();
        
        int n2 = grid2.size();
        int m2 = grid2[0].size();
        
       
        vector<vector<int>> vis2(n2 , vector<int>(m2, 0));
        
        int cnt=0;
        
        for(int i=0 ;i<n1;i++){
            for(int j=0 ;j<m1 ;j++){
                if(grid2[i][j]==1 && !vis2[i][j]){
                    int ans=1;
                    
                    dfs(i , j , vis2 , grid1 , grid2 , ans);
                    cnt+=ans;
                    
                }
            }
            
        }
        return cnt;
    }
};