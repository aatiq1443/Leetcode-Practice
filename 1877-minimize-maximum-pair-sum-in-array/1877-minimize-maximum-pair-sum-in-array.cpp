class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int low = 0, high = nums.size()-1;
        int maxi = INT_MIN;
        
        while(low < high)  {
            maxi = max(maxi, nums[low++] + nums[high--]);
        }
                       
        return maxi;
        
    }
};