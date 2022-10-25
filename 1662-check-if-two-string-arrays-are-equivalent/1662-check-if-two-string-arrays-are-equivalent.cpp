class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1 = "";
        string str2 = "";
        
        for(int i=0 ; i<word1.size() ;i++){
            
            string temp = word1[i];
            str1 = str1+temp;
            
        }
       
        for(int i=0 ; i<word2.size() ;i++){
            
            string temp = word2[i];
            str2 = str2+temp;
            
        }
       
        if(str1 == str2) return true;
        
        return false;
        
    }
};