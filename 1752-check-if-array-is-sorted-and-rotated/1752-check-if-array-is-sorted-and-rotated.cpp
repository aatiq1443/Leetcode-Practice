class Solution {
public:
    
//     int solve(vector<int> &nums , int n){
        
//         int s = 0; 
//         int e = n-1;
        
//         while(s < e){
//             int mid = s + (e-s)/2;
            
//             if(nums[mid] > nums[n-1]){
//                 s = mid+1;
//             }
//             else e = mid;
            
//         }
        
//         return s;
//     }
    
    bool check(vector<int>& nums) {
        
//         int n = nums.size();
        
//         int pivot = solve(nums  , n);
        
//         if(nums[pivot] == *min_element(nums.begin() , nums.end())) return true;
        
//         else return false;
        int count=0;
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        
        if(nums[nums.size()-1]>nums[0]){
            count++;
        }
        
        if(count>1){
            return false;
        }
        
        return true;

        
    }
};