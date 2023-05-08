class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
             int sum = 0, size = mat.size();
        for (int i = 0; i < size; i++){
            if (i != size-i-1){
                sum += mat[i][i] + mat[i][size-i-1];
            }
            else{
                sum += mat[i][i];
            }
        }
        return sum;
    }
};