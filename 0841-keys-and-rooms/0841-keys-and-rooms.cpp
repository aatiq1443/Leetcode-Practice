class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        
        queue<int>q;
        
        vector<bool>vis(n , false);
        vis[0] =true;
        
        for(int i=0 ;i<m ;i++){
            q.push(rooms[0][i]);
        }

        
        while(!q.empty()){
            int temp = q.front();
            int size = rooms[temp].size();
            q.pop();
            vis[temp] =true;
            
            for(int i=0 ;i<size ;i++){
                if(!vis[rooms[temp][i]])
                    q.push(rooms[temp][i]);
            }
            
        }
        
        for(int i=0 ;i<vis.size();i++){
            if(vis[i]==false) return false;
        }
        
        return true;
        
    }
};