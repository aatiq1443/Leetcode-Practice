class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);      
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
            ans.push_back(nums[i]);
        }
        return ans;
    }
};