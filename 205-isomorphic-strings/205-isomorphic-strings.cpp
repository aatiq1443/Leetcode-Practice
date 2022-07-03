class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp1[s[i]]=i+1;
            mp2[t[i]]=i+1;
        }
         for(int i=0;i<n;i++){
            if(mp1[s[i]] != mp2[t[i]]) return false;
        }
        return true;
    }
};