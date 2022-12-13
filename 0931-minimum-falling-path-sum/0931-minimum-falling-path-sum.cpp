class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
         int n = matrix.size();
        
        int m = matrix[0].size();
          
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                
                
                int mini = matrix[i - 1][j];
                
                
                if(j - 1 >= 0){
                    mini = min(mini, matrix[i - 1][j - 1]);
                }
                
                
                if(j + 1 < m){
                    mini = min(mini, matrix[i - 1][j + 1]);
                }
                
                
                matrix[i][j] += mini;
            }
        }
        
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
        
    }
};