class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
       queue<pair<pair<int , int> , int>>q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int>(m ,0));
        
        int flag=0;
        
        for(int i=0 ; i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(grid[i][j] ==0) flag=1;
            }
        }
        if(flag==0) return -1;
        
        flag=0;
        
        for(int i=0 ; i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(grid[i][j] ==1) flag=1;
            }
        }
        if(flag==0) return -1;
        
        for(int i=0 ;i< n ;i++){
            for(int j=0 ;j<m ;j++){
                if (grid[i][j]==1){
                    vis[i][j] = 1;
                    q.push({{i , j} , 0});
                }
            }
        }
        
        int delrow[]={-1 , 0 , +1 , 0};
        int delcol[]={0  , +1 , 0 , -1};
        int maxi = 0;
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxi = max(maxi , time);
            for(int i=0 ; i<4;i++){
               
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 ){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow , ncol} , time+1});
                    }
                    
                
            }
            
        }
        return maxi;
    }
};