class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0;
        int j=0;
       while(i<n && j<m){
           if(s[i]==t[j]) i++;
           j++;
       }
        if(n==i) return  true;
        return false;
    }
};