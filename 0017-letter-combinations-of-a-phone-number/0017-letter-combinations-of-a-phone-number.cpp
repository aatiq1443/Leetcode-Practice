class Solution {
private:
    void solve(string digits , vector<string>&ans , string output , string map[], int n , int in){
        if(in==n){
            ans.push_back(output);
            return ;
        }
        
        int data=digits[in]-'0';
        string value=map[data];
        for(int i=0;i<value.size();i++){
            output.push_back(value[i]);
            solve(digits , ans , output , map , n ,in+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        
        vector<string> ans;
        if(n==0)
            return ans;
        string output="";
        string map[]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , ans , output , map  , n , 0);
        return ans;
    }
};