class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int n = arr.size();
        int st = 0;
        int end = n-1;
        
        while(st<end){
            int mid = st + (end-st)/2;
            
            if(arr[mid] > arr[n-1]){
                st = mid+1;
            }
            else end = mid;
            
        }
        return arr[st];
        
    }
};