class Solution {
public:
int getPivot(vector<int> &nums , int n){
int st = 0 ;
int end = n-1;
while(st<end){
int mid = st + (end-st)/2;
if(nums[mid] >= nums[0]){
st = mid+1;
}
else end = mid;
}
return st;
}
int binarySearch(vector<int> &nums , int s , int e , int target){
int st = s;
int end = e;
while(st<=end){
int mid = st + (end-st)/2;
if(nums[mid] == target){
return mid;
}
else if(nums[mid] < target){
st = mid+1;
}
else end = mid-1;
}
return -1;
}
int search(vector<int>& nums, int target) {
int n = nums.size();
int pivot = getPivot(nums , n);
if(target >=nums[pivot] && target<=nums[n-1]){
return binarySearch(nums , pivot , n-1 , target);
}
else{
return  binarySearch(nums , 0 , pivot-1 , target);
}
}
};