class Solution {
public:
    
    int second_occ(vector<int> &nums , int target){
        
        int st = 0;
        int end = nums.size() -1 ;
        
        int ans = -1;
        
        while(st<=end){
            int mid = st + (end-st) /2;
            
            if(nums[mid] == target){
                ans = mid;
                st = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
    
    
    int frist_occ(vector<int> &nums , int target){
        
        int st = 0;
        int end = nums.size() -1 ;
        
        int ans = -1;
        
        while(st<=end){
            int mid = st + (end-st) /2;
            
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
        
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
       int first = frist_occ(nums , target);
       int second = second_occ(nums , target);
        vector<int> ans;
        
        ans.push_back(first);
        ans.push_back(second);
        
        return ans;
        
    }
};