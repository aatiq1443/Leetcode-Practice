class Solution {
public:
    bool isAnagram(string s, string t) {
        
         if(s.size() != t.size()) return false;
        
        map<char, int> mapp1, mapp2;
        for(int i=0; i<s.size(); i++)
        {
            mapp1[s[i]]++;
            mapp2[t[i]]++;
        }
        
        if(mapp1==mapp2) return true;
        return false;
    }
};