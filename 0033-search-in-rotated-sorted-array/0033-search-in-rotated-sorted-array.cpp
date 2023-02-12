class Solution {
public:
    
    int findMin(vector<int> &arr ){
        
        int n= arr.size();
        
        int st = 0 ;
        int end = n-1;
        
        while(st < end){
            int mid = st + (end - st)/2;
            
            if(arr[mid] > arr[n-1]){
                st = mid+1;
            }
            else {
                end = mid;
            }
            
        }
        
        return st;
    }
    
    int binarySearch(vector<int> &ans , int target , int st ,int end){
        
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(ans[mid] == target) return mid;
            
            else if(ans[mid] < target) st = mid+1;
            
            else  end = mid-1;
        }
        
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        
        int st = 0 ;
        int end = nums.size() -1 ;
        
        int index = findMin(nums);
        
        int first = binarySearch(nums , target , st , index-1);
        int second = binarySearch(nums , target , index , end);
        
        if(first == -1 && second == -1) return -1;
        
         if(first == -1 && second != -1) return second;
        
         return first;
        
        
        
    }
};