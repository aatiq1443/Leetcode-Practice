class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int left =0 ;
        int right = n-1;
        
//         int maxLeft =0;
//         int maxRight =0;
        
//         int ans =0;
        
//         while(left<=right){
//             if(height[left] <= height[right]){
//                 if(height[left]> maxLeft){
//                     maxLeft = height[left];
//                 }
//                 else{
//                     ans = ans+ (maxLeft - height[left]);
//                 }
//                 left++;
//             }
//             else if(height[right] <= height[left]){
//                 if(height[right] >maxRight){
//                     maxRight = height[right];
//                 }
//                 else{
//                     ans = ans+ (maxRight - height[right]);
//                 }
//                 right--;
//             }
//         }
//         return ans;
        
//     }
    
    int maxleft= 0;
    int maxright = 0 ;
    
        int ans = 0;
    
    
    while(left <= right) {
        
            if(height[left] <= height[right]){
                if(height[left] > maxleft) maxleft = height[left];

                else{
                    ans = ans + (maxleft - height[left]);
                }
                left++;
            }

            else if(height[right] <= height[left]){

                if(height[right] > maxright) maxright = height[right];

                else{
                    ans = ans + (maxright - height[right]);
                }
                right--;

                }
        
        }  
        return ans;
    }
    
};









