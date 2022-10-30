class Solution {
public:
    
    
    bool isPossible(vector<int> &nums , int mid , int k){
        
        int split_sum = 0;
        int split_cnt = 1;
        
        for(int i=0 ; i<nums.size() ;i++){
            if(split_sum + nums[i] <= mid){
                split_sum += nums[i];
            }
            else{
                split_cnt++;
                if(split_cnt > k || nums[i] > mid) return false;
                split_sum = nums[i];
            }
        }
        return true;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int n =nums.size();
        
        int st = 0;
        int end = accumulate(nums.begin() , nums.end() , 0);
        
        int ans = -1;
        
        while(st <= end){
            
            int mid = st +  (end - st) /2;
            
            if(isPossible(nums , mid , k)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid +1 ;
            }
            
        }
        return ans;
    }
};