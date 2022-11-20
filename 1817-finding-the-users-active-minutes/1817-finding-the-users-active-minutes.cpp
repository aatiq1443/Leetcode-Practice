class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        unordered_map< int , set<int> >mp;
        
        for(auto it:logs){
            
            int temp1=it[0];
            int temp2=it[1];
            
            mp[temp1].insert(temp2);
        }
        
        vector<int> ans (k,0);
        
        for(auto it:mp){
            
            ans[it.second.size() - 1]++;
        }
        return ans;
        
    }
};