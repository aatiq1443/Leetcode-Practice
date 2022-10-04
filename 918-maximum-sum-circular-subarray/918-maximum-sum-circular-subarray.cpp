class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int max_sum=INT_MIN;
        int min_sum=INT_MAX;
        int curr_min=0;
        int curr_max=0;
        int totalsum=0;
        
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
            
            curr_max=max(nums[i],nums[i]+curr_max);
            max_sum=max(max_sum,curr_max);
            
            curr_min=min(nums[i],nums[i]+curr_min);
            min_sum=min(min_sum,curr_min);
        }
        if(max_sum>0)
            return max(max_sum,totalsum-min_sum);
        return*max_element(nums.begin(),nums.end());
    }
};