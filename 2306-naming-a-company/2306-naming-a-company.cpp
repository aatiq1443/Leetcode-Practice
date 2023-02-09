class Solution {
public:
    #define ll long long 
    long long distinctNames(vector<string>& ideas) {
       unordered_set<string>st[26];
       ll ans=0;
       for(auto s:ideas){
           st[s[0]-'a'].insert(s.substr(1));
       }
       for(int i=0;i<25;i++){
           for(int j=i+1;j<26;j++){
               ll c1=0,c2=0;
               for(auto x:st[i])c1+=(!st[j].count(x));
               for(auto x:st[j])c2+=(!st[i].count(x));
               ans+=(c1*c2);
           }
       }
       ans*=2ll;
       return ans;
    }
};