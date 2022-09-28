class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        
        vector<int>vec;
        
        for(int i=0;i<groupSizes.size();i++) {
            mp[groupSizes[i]].push_back(i);
        }
        
        for(auto it:mp) {
            
            for(int i=0;i<it.second.size();i++) {
                
                vec.push_back(it.second[i]);
                if((i+1)%it.first==0) {
                    
                    ans.push_back(vec);
                    vec.clear();
                }
            }
            
        }
        return ans;
    }
};