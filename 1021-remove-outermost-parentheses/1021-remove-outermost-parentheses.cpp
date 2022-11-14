class Solution {
public:
    string removeOuterParentheses(string S) {
        
        stack<char> st;
        
        string ans;
        
        for(char c: S){
            
            if(c == ')') st.pop();
            
            if(!st.empty()) ans += c;
            
            if(c == '(') st.push(c);
            
        }
        
        return ans;
        
    }
};