class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // if(magazine.size()<ransomNote.size()) return false;
      
        map<char , int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }
        int count=0;
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
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
        // for(auto i:mp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        cout<<count;
        if(count==ransomNote.size()) return true;
        return false;
        
        
    }
};