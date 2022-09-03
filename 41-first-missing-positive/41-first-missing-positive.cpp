class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        // placed all elements with their corresponding index
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i] , nums[nums[i]-1]);
            }
        }
        
        // check which element is not placed at the right index
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;         // return i+1 because index start from 0
            }
        }
        
        
        // if all elements are places in the right index return size+1
        return n+1;
    }
};