class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n = s.size(), vow = 0, ans;
        
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vow++;
        }
        
        ans = vow;
        
        for(int i = 0; i < n-k; i++){
            
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vow--;
            if(s[i+k] == 'a' || s[i+k] == 'e' || s[i+k] == 'i' || s[i+k] == 'o' || s[i+k] == 'u') 
                vow++;
            
            ans = max(ans, vow);
            
        }
        
        return ans;
        
    }
};