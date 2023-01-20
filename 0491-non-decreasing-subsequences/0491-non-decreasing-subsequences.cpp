class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> seq(1);
        set<vector<int>> bst;
        
        for(int i=0;i<nums.size();i++) {
            
            int n = seq.size();
            
            for(int j=0;j<n;j++)
                
                if(seq[j].empty() || seq[j].back()<=nums[i]) {
                    
                    seq.push_back(seq[j]);
                    seq.back().push_back(nums[i]);
                    if(seq.back().size()>1) bst.insert(seq.back());
                    
                }  
        }
        
        return vector<vector<int>>(bst.begin(),bst.end());
        
    }
};