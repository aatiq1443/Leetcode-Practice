class Solution {
public:
    int beautySum(string s) {
        
        int l,m;
        
        unordered_map<char,int> mp;
        
        int res=0;
        
        for(int i=0;i<s.length();i++){
            
            mp.clear();
            
            for(int j=i;j<s.length();j++){
                
                mp[s[j]]++;
                if(j-i>1){
                    
                    m=0;
                    l=INT_MAX;
                    
                    for(auto i : mp){
                        
                        m = max(i.second,m);
                        l = min(i.second,l);
                        
                    }
                    
                    res+=m-l;
                }
            }
        }
        
        return res;
        
    }
};