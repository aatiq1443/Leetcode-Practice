class Solution {
public:
    string reverseWords(string str) {
        
        string word, ans="";
        
        stringstream ss(str); 
        
        while(ss>>word){
            ans = word + " " + ans;
        }
        
        ans.pop_back();
        
        return ans;
        
    }
};