class Solution {
public:
    bool checkIfPangram(string str) {
        
        unordered_map<char , int> mp;
        
        for(auto i:str){
            mp[i]++;
        }
        
        return mp.size() >= 26 ? true : false;
        
    }
};