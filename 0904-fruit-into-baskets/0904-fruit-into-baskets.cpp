class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        unordered_map<int,int> m;
        int n=tree.size();
        
        int l=0,r=0,ma=0,ct=0;
        
        
        while(r<n){
            
            if(m[tree[r]]==0) ct++;
            
            m[tree[r]]++;
            r++;
            
            while(l<r && ct>2){
                
                m[tree[l]]--;
                if(m[tree[l]]==0) ct--;
                l++;
                
            }
            
            ma=max(ma,r-l);
            
        }
        
        return ma;
        
    }
};