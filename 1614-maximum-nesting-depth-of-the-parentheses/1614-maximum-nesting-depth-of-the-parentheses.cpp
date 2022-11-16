class Solution {
public:
    int maxDepth(string s) {
        
        int c=0;
		int l=0;
        for(int i=0;i<s.length();i++){

            if(s[i]=='(') l++;

            else if(s[i]==')')l--;
            c=max(c,l); 

        }
        
        return c;
        
    }
};