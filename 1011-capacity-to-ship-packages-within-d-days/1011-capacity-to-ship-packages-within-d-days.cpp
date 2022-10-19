class Solution {
public:
    
    bool isPossible(int n , int m , int mid , vector<int> &arr){
        
        int package = 0 ;
        int ship_cnt = 1;
        
        for(int i=0 ; i<n ;i++){
            if(package + arr[i] <= mid){
                package+=arr[i];
            }
            else{
                ship_cnt++;
                if(ship_cnt > m || arr[i] > mid) return false;
                package = arr[i];
            }
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& arr, int days) {
        
        int n = arr.size();
        int st = 0 ;
        int sum = 0;
        
        for(int i=0 ; i<n ;i++){
            sum+=arr[i];
        }
        
        int end = sum;
        int ans =-1;
        
        while(st<=end){
            int mid = st + (end-st)/2;
            
            if(isPossible(n , days , mid , arr)){
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