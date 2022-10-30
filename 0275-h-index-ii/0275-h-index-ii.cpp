class Solution {
public:
    int hIndex(vector<int>& arr) {
        
        int n = arr.size();
        
      
        
        int st = 0;
        int end = n-1;
        
        while(st <= end){
            int mid = st + (end-st)/2;
            
            if(arr[mid] == n-mid){
                return arr[mid];
            }
            
            else if(arr[mid] > n-mid){
                end = mid-1;
            }
            else st = mid+1;
            
        }
        return n-st;
        
    }
};