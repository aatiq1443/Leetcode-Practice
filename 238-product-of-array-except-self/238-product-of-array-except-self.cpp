class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int sum_product=1 , count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) sum_product*=nums[i];
            else count++;
        }
        if(count==0){
            for(int i=0;i<n;i++){
                nums[i]=sum_product/nums[i];
            }
        }
        else if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]!=0) nums[i]=0;
                else
                    nums[i]=sum_product;
            }
        }
        else{
            for(int i=0;i<n;i++){
                nums[i]=0;
            }
        }
        return nums;
    }
};