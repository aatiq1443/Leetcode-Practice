class Solution {
public:
    int minPartitions(string str) {
        
        
        int ans = 0;
        
        for(auto it : str){
            
            int digit = it - '0';
            ans = max(ans , digit);
            
        }
        
        return ans;
        
    }
};