class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> vec;
        
        int i =0 ; 
        int j = 0;
        
        int maxi = 0;
        int ans = 0;
        
        while(j <s.size()){
            vec[s[j]]++;
            maxi = max(maxi , vec[s[j]]);
            
            if((j-i+1)-maxi <=k){
                ans = max(ans , j-i+1);
                j++;
            }
            
            else if((j-i+1)-maxi > k){
                 while((j-i+1)-maxi > k){
                     vec[s[i]]--;
                     i++;
                 }
                j++;
            }
            
        }
        return ans;
        
    }
};