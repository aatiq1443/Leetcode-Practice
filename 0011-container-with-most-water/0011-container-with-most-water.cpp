class Solution {
public:
    int maxArea(vector<int>& height) {
        
    int max=0,s=0,ans=0,i=0,j=height.size()-1;
    while(i<j){
        if(height[j]<height[i]){
           s=height[j];
               
            }
            else{
                s=height[i];
                
            }
            
            ans=(j-i)*s;
            if(max<ans)
                max=ans;
       
       if(height[j]<height[i])
               j--;
            else
                i++;
            
           }
    
    
    return max;
        
    }
};