class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int row = board.size();
    int col = board[0].size();
    
    unordered_set<string> myset;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j] != '.'){
                
                int num=board[i][j]-'0';
            
                string s1 ="row"+to_string(i) + to_string(num);
                string s2 ="col"+to_string(j) + to_string(num);
                string s3 ="box"+to_string(i/3*3+j/3)+to_string(num);
            
                if(myset.find(s1) != myset.end() or myset.find(s2) != myset.end() or myset.find(s3) != myset.end())
                    return false;
            
                myset.insert(s1);
                myset.insert(s2);
                myset.insert(s3);
            }
         }
    }
    
    return true;
        
    }
};