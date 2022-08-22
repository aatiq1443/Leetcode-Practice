class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256 , -1);
        int n=s.size();
        int maxLen=0;
        int start=-1;
        
        for(int i=0;i<n;i++){
            if(pos[s[i]] > start)
                start=pos[s[i]];
            pos[s[i]]=i;
            
            maxLen=max(maxLen , (i-start));
        }
        
        return maxLen;
    }
};