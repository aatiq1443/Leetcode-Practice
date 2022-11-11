class Solution {
private:
 
    
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
public:
    bool isPalindrome(string su) {
   
        string s="";
        
        for(int i=0;i<su.length();i++){
            if (( su[i]>='a' && su[i]<='z')|| ( su[i]>='A' && su[i]<='Z') || ( su[i]>='0' && su[i]<='9')  ){
                s.push_back(su[i]);
            }
        }
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        return check(s);
       
    }
};