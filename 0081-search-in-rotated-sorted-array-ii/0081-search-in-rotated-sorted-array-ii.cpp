class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
       int st=0;
       int end=nums.size()-1;
        while(st<=end){
            
            while(st<end && nums[st]==nums[st+1])  st++;
            while(end>st && nums[end]==nums[end-1])  end--;
            
            int mid = st + (end-st)/2;
            if(nums[mid] == target)return true;
            
            if(nums[mid] >= nums[st]){
                if(target>=nums[st] && target<nums[mid]) end = mid-1;
                else st = mid+1;
            }
            
            else{
                if(target<=nums[end] && target>nums[mid]) st = mid+1;
                else end = mid-1;
            }
        }
        
        return false;
        
    }
};