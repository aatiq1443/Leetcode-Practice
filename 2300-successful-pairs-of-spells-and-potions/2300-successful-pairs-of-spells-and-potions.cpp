class Solution {
     #define ll long long
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long c) {
        
         sort(p.begin(),p.end());
        
        vector<int>ans;
        
        for(int i=0;i<s.size();i++){
            
            int d=0;
            ll g=c/s[i];
            
            if(c%s[i])g++;
            
            int f=lower_bound(p.begin(),p.end(),g)-p.begin();
            
            d += p.size()-f;
            ans.push_back(d);
        }
        
        return ans;
    }
};