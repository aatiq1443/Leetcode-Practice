class Solution {
public:
int countSub(vector<int>&ans , int n ,int sum){
int dp[n+1][sum+1];
​
for(int i=0;i<n+1;i++){
for(int j=0;j<sum+1;j++){
if(i==0) dp[i][j]=0;
if(j==0) dp[i][j]=1;
}
}
​
for(int i=1;i<n+1;i++){
for(int j=0;j<sum+1;j++){
if(ans[i-1]<=j){
dp[i][j]=dp[i-1][j-ans[i-1]] + dp[i-1][j];
}
else{
dp[i][j]=dp[i-1][j];
}
}
}
return dp[n][sum];
}
int findTargetSumWays(vector<int>& nums, int target) {
int n=nums.size();
if(n==1 && nums[0]!=abs(target)) return 0;
if(n==1 && nums[0]==abs(target)) return 1;
int temp=accumulate(nums.begin(),nums.end(),0);
cout<<temp;
int sum=(temp+target)/2;
return countSub(nums,n,sum);
}
};