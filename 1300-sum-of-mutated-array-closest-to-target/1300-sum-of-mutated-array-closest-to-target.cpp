class Solution {
public:
    int solve(vector<int>& vec, int k, int target){
        
        int sum=0;
        
        for(int i=0 ; i <vec.size() ; i++){
            if(vec[i] >= k){
                sum += k;
            }
            else sum += vec[i];
        }
        
        return abs(sum-target);
    }
    
    
    int findBestValue(vector<int>& arr, int target) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int st = 0;
        int end = *max_element(arr.begin() , arr.end());
        
        while(st <= end){
            
            int mid = st + (end-st)/2;
            
            int x1 = solve(arr , mid , target);
            int x2 = solve(arr , mid+1 , target);

            if(x1 > x2){
                st = mid+1;
            }
            else end = mid-1;

        }
        
        return st;
        
        
    }
};