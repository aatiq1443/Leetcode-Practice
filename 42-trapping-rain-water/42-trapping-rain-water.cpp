class Solution {
public:
   
    int trap(vector<int>& nums) {
        
        
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int left=0;
        int right=n-1;
        
        int maxLeft=0;
        int maxRight=0;
        
        int result=0;
        
        while(left<=right){
            
            if(nums[left]<=nums[right]){
                if(nums[left]>=maxLeft){
                    maxLeft=nums[left];
                }
                else{
                    result= result + maxLeft - (nums[left]);
                }
                left++;
            }
            
            if(nums[right]<=nums[left]){
                if(nums[right]>=maxRight){
                    maxRight=nums[right];
                }
                else{
                    result= result + maxRight - (nums[right]);
                }
                right--;
            }
            
        }
        return result;
    }
};