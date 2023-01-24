class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int sz = board.size(); int target = sz * sz ;
        unordered_map<int, int> moves; 
        moves[1] = 0; 
        queue<int> q ; q.push(1); 
        
        while(!q.empty())
        {
            int current_sq = q.front(); q.pop();
            
            for(int i=1; i<=6; i++)
            {
                int next_sq = current_sq + i ; 
                if(next_sq > target){break;}
                
                int row = (next_sq - 1)/sz ;
                int col = (row % 2 == 0) ? (next_sq - 1) % sz : sz - 1 - ((next_sq-1) % sz)  ;
                
                if(board[sz-1-row][col] != -1)
                {
                    next_sq = board[sz-1-row][col] ;
                }
                if(moves.count(next_sq) == 0)
                {
                    moves[next_sq] = moves[current_sq] + 1;
                    if(next_sq == target){return moves[next_sq];}
                    q.push(next_sq);
                }
            }
        }
        
        return -1 ;
        
    }
};