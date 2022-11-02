class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26);
        vector<bool>vis(26);
        
        string ans = "";
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) last[s[i]-'a'] = i;        
        
        for(int i = 0; i < n; i++){
            
            if(vis[s[i] - 'a']) continue;
 
            while(!ans.empty() && ans.back() > s[i] && last[ans.back()-'a'] > i){
                
                vis[ans.back() - 'a'] = false;      
                ans.pop_back();
            }
            
            ans.push_back(s[i]);      
            vis[s[i] - 'a'] = true; 
        }
        
        return ans;
    }
};