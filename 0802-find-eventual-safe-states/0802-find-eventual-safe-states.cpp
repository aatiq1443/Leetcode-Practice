class Solution {
public:
   void dfs(int k,vector<vector<int>>& graph,vector<bool> &visited, vector<bool> &safe )
    {
        visited[k]=true;
        bool flag=true;
        for(auto x:graph[k])
        {
            if(!visited[x])
            {
                dfs(x,graph,visited,safe);
            }
            flag=flag&safe[x];
        }
        safe[k]=flag;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        vector<bool>visited(graph.size(),false);
        vector<bool>safe(graph.size(),false);
        
        for(int i=0;i<graph.size();i++)
        {
            if(!visited[i])
                dfs(i,graph,visited,safe);
        }
        for(int i=0;i<graph.size();i++)
        {
            if(safe[i])
               res.push_back(i);
        }
        return res;
    }
};