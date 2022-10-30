class Solution {
public:
    
   int solve(vector<int> &nums ,int mid){
       int sum = 0 ;
       
       for(int i=0 ;i<nums.size(); i++){
           if(nums[i]%mid == 0){
               sum = sum + (nums[i]/mid);
           }
           else{
               sum = (sum + (nums[i]/mid)) +1;

           }
       }
       return sum;
   }
    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        
        int st = 1;
        int end = 1000001;
        
        int ans = 0;
        
        while( st <= end ){
            
            int mid = st + (end-st)/2;
            
            long long int divisor = solve(nums , mid);
            
            if(divisor > threshold){
                st = mid +1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
                
        }
        
        return ans;
        
        
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     int smallestDivisor(vector<int>& nums, int threshold) {
        
//         int l=1,r=1000001;
//         int ans=0;
//         while(l<=r){
//             int mid=l+(r-l)/2;
//             long long int sum=0;
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]%mid==0){
//                     sum+=(nums[i]/mid);
//                 } else{
//                     sum+=(nums[i]/mid)+1;
//                 }
//             }
//             if(sum>threshold){
//                 l=mid+1;
//             } else{
//                 ans=mid;
//                 r=mid-1;
//             }
//         }
//         return ans;
        
//     }
// };