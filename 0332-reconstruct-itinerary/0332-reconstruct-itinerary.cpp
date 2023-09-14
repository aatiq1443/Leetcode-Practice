class Solution {
    
    unordered_map <string, multiset <string>> maptickets;       
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector <string> t: tickets)    
            maptickets[t[0]].insert(t[1]); 
        
        vector <string> result;
        dfs (result, "JFK");                 
        reverse (result.begin(), result.end());
        return result;                      
    }
    
    void dfs (vector <string> &result, string source) {
        while (!maptickets[source].empty()) {
            string dest = *maptickets[source].begin();    
            maptickets[source].erase (maptickets[source].begin());  
            dfs (result, dest);                                  
        }
        result.push_back(source);                                   
    }    
};