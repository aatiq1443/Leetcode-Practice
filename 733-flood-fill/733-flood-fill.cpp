class Solution {
public:
    void dfs(int i , int j , vector<vector<int>> &image , int target , int newcolor){
        
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() 
           || image[i][j]==newcolor || image[i][j]!=target) {
            return ;
        }
        
        image[i][j]= newcolor;
        
        dfs(i-1 , j , image , target , newcolor);
        dfs(i+1 , j , image , target , newcolor);
        dfs(i , j-1 , image , target , newcolor);
        dfs(i , j+1 , image , target , newcolor);
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        dfs(sr , sc , image , image[sr][sc] , color);
        
        return image;
        
    }
};