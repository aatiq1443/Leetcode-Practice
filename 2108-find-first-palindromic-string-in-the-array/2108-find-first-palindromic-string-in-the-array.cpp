class Solution {
public:
    
    bool check(string s){
        
        int a=0;
        int b=s.length()-1;
        
        while(a<b){
            if(s[a]!=s[b]) {
                return 0;
            }
            else{
                a++;
                b--;
             }
        }
        
        return 1;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0 ; i<words.size() ;i++){
            if(check(words[i])){
                
                return words[i];
                
            }
        }
        return "";
    }
};