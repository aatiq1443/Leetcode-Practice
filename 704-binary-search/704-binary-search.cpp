class Solution {
private:
    int solve(vector<int> & arr,int target , int s, int e){
        int temp;
        if(s>e) return -1;
        int mid= s + (e-s)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target){
            return solve(arr,target,s,mid-1);
        }
        else{
            return solve(arr,target,mid+1,e);
        }
        
    }
public:
    int search(vector<int>& nums, int target) {
    int n=nums.size();
      int s=0;
        int e=n-1;
       int ans= solve(nums,target,s,e);
        return ans;
        
    }
};