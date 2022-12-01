class Solution {
public:
    bool halvesAreAlike(string s) {
    
        string str = "aeiouAEIOU";
        
        int i =0 ;
        int j = s.size() - 1 ;
        
        int i_cnt = 0;
        int j_cnt = 0;
        
        while( i < j){
            if(str.find(s[i]) < str.length()) i_cnt++;
            if(str.find(s[j]) < str.length()) j_cnt++;
            
            i++;
            j--;
        }
        

        
        return i_cnt == j_cnt;
        
    }
};