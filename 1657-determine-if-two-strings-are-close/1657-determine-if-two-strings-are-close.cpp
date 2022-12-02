class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length() != word2.length()) return false;
        
        int count1[26] = {0};
        int count2[26] = {0};
        
        for(int i = 0;i < word1.length(); i++){
            count1[word1[i]-'a']++;
        }
        
        for(int i = 0; i < word2.length();  i++){
            count2[word2[i]-'a']++;
        }
        
        for(int i = 0;i < 26 ;i++){
            if(count1[i] && count2[i] == 0) return false;
        }
        
        sort(count1,count1+26);
        sort(count2,count2+26);
        
        for(int i = 0; i < 26; i++) {
            
            if(count1[i] != count2[i]) return false;
        }
        
        return true;
        
    }
};