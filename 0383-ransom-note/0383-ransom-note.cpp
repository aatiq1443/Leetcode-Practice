class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) { 
        map<char , int> mp;
        
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }
        
        int count=0;
        
        for(int i=0;i<magazine.size();i++){
            if(mp.count(magazine[i])){
                count++;
                if(mp[magazine[i]]==1){
                    mp.erase(magazine[i]);
                }
                else{
                    mp[magazine[i]]--;
                }
                
            }
        }
        
        if(count==ransomNote.size()) return true;
        
        return false;
    }
};