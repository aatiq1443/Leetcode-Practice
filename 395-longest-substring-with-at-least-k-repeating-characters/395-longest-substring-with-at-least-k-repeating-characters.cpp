class Solution {
public:
    int longestSubstring(string s, int k) {
        
       int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            int tmp = 0;
            unordered_map<char, int> mp;
            int cnt = 0;
            
            for(int j = i; j < s.length(); j++){
                
                if(mp[s[j]] +1 == k)
                    tmp++;
                
                mp[s[j]]++;
                cnt++;
                
                if(mp.size() == tmp){
                    ans = max(ans, cnt);
                }
                
            }
        }
        return ans;
    }
};