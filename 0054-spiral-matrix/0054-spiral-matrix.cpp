class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int stRow=0;
        int stCol=0;
        int endRow=row-1;
        int endCol=col-1;
        int total=row*col;
        int count=0;
        vector<int> ans;
        while(count < total){
            // print startrow
            for(int index=stCol ; count<total && index<=endCol ; index++){
                ans.push_back(matrix[stRow][index]);
                count++;
            }
            stRow++;
            //print ending col
            
            for(int index=stRow ; count<total && index<=endRow ; ++index){
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;
            //print ending row
            for(int index=endCol ; count<total &&index>=stCol ; index--){
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;
            //print starting col
            for(int index=endRow ; count<total && index>=stRow ; index--){
                ans.push_back(matrix[index][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }
};