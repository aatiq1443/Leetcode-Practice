class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                       vector<int> pos(256,-1); 
        int maxLen=0;
        int start=-1;
        for(int i=0;i<s.length();i++)
        {
            // if the position of any character of string is greater than start , then it means that character has already occured before, so now we need to update our start to that previous position of the character.
            if(pos[s[i]]>start)
            {
                start=pos[s[i]];
            }
            // we will mark the position of the character is equal to i
            pos[s[i]]=i;
            // updating the maximum length of longest substring
            maxLen=max(maxLen,i-start);
        }
        
        return maxLen;
    }
};