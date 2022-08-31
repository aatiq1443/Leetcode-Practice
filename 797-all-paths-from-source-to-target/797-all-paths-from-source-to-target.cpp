class Solution {
public:
    
    void solve(int data , vector<vector<int> > &ans , vector<int> &ds , vector<vector<int>> &graphs){
        
        
        ds.push_back(data);
        
        if(data == graphs.size()-1){
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        
        for(int i=0;i< graphs[data].size();i++){
            
            solve(graphs[data][i] , ans , ds, graphs);
            
        }
        
        ds.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        solve( 0 , ans , ds , graph);
        return ans;
    }
};