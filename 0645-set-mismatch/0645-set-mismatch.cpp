class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n  = nums.size();
        sort(nums.begin() , nums.end());
        
        int dupl = -1;
        
        for (int i = 0; i<n-1; i++) {
            if (nums[i] == nums[i + 1]) {
                dupl = nums[i];
                break;
            }
        }
        int sum = (n+1)*n/2;
        for (int i =0; i<n; i++) {
            sum -= nums[i];
        }
        
        vector<int> ans;
        
        ans.push_back(dupl);
        ans.push_back(sum+dupl);
        
        return ans;
    }
};