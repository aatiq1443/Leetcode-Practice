class Solution {
public:
    
 int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = 10000000000;
        
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int time = timefnc(mid,piles);
            
            if(time<=h){
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
            
        }
        
        return ans;
        
    }
    
    int timefnc(int mid,vector<int>&piles)
    {
        int sum = 0;
         
        for(int i=0;i<piles.size();i++){
            
            sum+=(piles[i]/mid)+((piles[i]%mid)!=0);
        }
        
        return sum;
    }
};