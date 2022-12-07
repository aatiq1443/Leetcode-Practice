class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int postfixsum = accumulate(nums.begin() , nums.end() , 0);   
        
        int prefixsum=0; 
        
        for(int i=0;i<nums.size();i++){
            
            postfixsum-=nums[i];
            
            if(postfixsum==prefixsum)
                return i;
            
            prefixsum+=nums[i];
        }
        
        return -1;
        
    }
};