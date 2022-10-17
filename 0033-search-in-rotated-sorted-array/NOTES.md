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