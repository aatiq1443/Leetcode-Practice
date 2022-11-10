class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans;
        
        for(auto i:s)
        {
            if(!ans.empty() and ans.back()==i)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        
        return ans;
        
    }
};