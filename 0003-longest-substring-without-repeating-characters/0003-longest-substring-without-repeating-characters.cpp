class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256 , 0);
        int n=s.size();
        int i=0 ; 
        int j= 0 ;
        int maxLen=0;
       
        
        while( j < s.length()){
            pos[s[j]]++;
            
            while(pos[s[j]] > 1){
                pos[s[i]]--;
                i++;
            }
            maxLen = max(maxLen , j-i+1);
            j++;
        }
        
        return maxLen;
    }
};