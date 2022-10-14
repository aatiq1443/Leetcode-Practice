class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>res(n);
        
        int x=0, y=0, z=0;
        res[0] = 1;
        
        for(int i=1; i<n; i++){
            
            res[i] = min(res[x]*2, min(res[y]*3,res[z]*5));
            
            if(res[i] == res[x]*2) x++;
            
            if(res[i] == res[y]*3) y++;
            
            if(res[i] == res[z]*5) z++;
            
        }
        
        return res[n-1];
        
    }
};