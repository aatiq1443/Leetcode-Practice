​
long long solve(vector<int> &nums , int mid){
long long sum = 0;
for(int i=0 ;i< nums.size() ;i++){
if(nums[i]%mid==0){
sum = (sum + (nums[i]/mid));
}
else
sum = (sum + (nums[i]/mid)) + 1;
}
return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
int n = nums.size();
int st = 0;
int end = 10000000000;
int ans = -1;
while( st <= end ){
int mid = st + (end-st)/2;
long long divisor = solve(nums , mid);