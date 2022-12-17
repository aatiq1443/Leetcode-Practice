class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
         stack<int>st;
        
        for(auto &t: tokens){
            
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                
                long long operator1= st.top(); st.pop();
                long long operator2= st.top(); st.pop();
                
                if(t=="+") operator1= operator2+operator1;
                
                if(t=="-") operator1= operator2-operator1;
                
                if(t=="*") operator1= operator2*operator1;
                
                if(t=="/") operator1= operator2/operator1;
                
                st.push(operator1);
            }
            
            else st.push(stoi(t));
        }
        
        return st.top();
        
    }
};