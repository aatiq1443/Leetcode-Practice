class Solution {
public:
    
    bool isPossible(int n , int operation , vector<int> &nums , int mid){
        
        for(int i= 0  ; i< n ;i++){
            operation -=(nums[i]/mid);
            if(nums[i]%mid== 0) operation++;
        }
        return operation>=0;
        
    }
    
    
    int minimumSize(vector<int>& nums, int m) {
        int n = nums.size();
        int st = 1;
        int end = *max_element(nums.begin() , nums.end());
        
        int ans = -1;
        while(st<=end){
            int mid =  st + (end-st)/2;
            
            if(isPossible(n , m , nums , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
     }
};