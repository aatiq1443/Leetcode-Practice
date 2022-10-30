class Solution {
public:
    
    int solve(vector<int> &piles , int mid){
        int sum = 0;
        
        for(int i=0 ; i< piles.size() ;i++){
            if(piles[i]%mid!=0){
                sum = (sum+(piles[i]/mid))+1;
            }
            else{
                sum = (sum+(piles[i]/mid));
            }
        }
        
        return sum;
    }
    
    
    int minimizedMaximum(int h, vector<int>& piles) {
        
         int n = piles.size();
        
        int st = 1;
        int end =10000000000;
        
        int ans = -1;
        while(st<=end){
            int mid = (st+end)/2;
            
            int time = solve(piles , mid);
            
            if(time <=h){
                ans = mid;
                end = mid-1;
            }
            else st = mid+1;
        }
        return ans;
        
        
    }
};