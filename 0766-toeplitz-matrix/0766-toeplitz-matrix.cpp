class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row-1;i++){
            for(int j=0;j<col-1;j++){
                if(mat[i][j]!=mat[i+1][j+1]) return false;
            }
        }
        return true;
    }
};