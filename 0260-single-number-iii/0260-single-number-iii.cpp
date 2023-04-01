class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        for (auto &num: nums) ++freq[num];
        
        vector<int> ans;
        
        for (auto &[x, f]: freq)
            
            if (f == 1) {
                
                ans.push_back(x);
                if (ans.size() == 2)
                    return ans;
                
            }
        
        return ans;
        
    }
};