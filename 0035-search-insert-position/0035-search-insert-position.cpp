class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s + (e-s)/2;
            if(target==nums[mid]) return mid;
            else if(nums[mid]>target) e=mid;
            else
                s=mid+1;
        }
        if(nums[s]<target) return s+1;
        return s;
    }
};