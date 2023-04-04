class Solution {
public:
    int partitionString(string s) {
        
        map<int, int> mp;
        int ans=0;
        
        for(auto i:s){
            
            if(mp[i] >0){
                ans++;
                mp.clear();
            }
            mp[i]++;
            
        }
        if(mp.size() >=1) ans++;
        
        return ans;
        
    }
};