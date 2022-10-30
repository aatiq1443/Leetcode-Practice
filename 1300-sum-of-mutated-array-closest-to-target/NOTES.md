int func(vector<int>& v, int k, int target){
int sum=0;
int n=v.size();
for(int i=0;i<n;i++){
if(v[i]>=k){
sum+=k;
}else{
sum+=v[i];
}
}
return abs(sum-target);
}
int findBestValue(vector<int>& arr, int target) {
sort(arr.begin(),arr.end());
int n=arr.size();
int mx=INT_MIN;
for(int i=0;i<n;i++){
mx=max(mx,arr[i]);
}
int l=0,r=mx;
while(l<=r){
int mid=l+(r-l)/2;
int x1=func(arr,mid,target);
int x2=func(arr,mid+1,target);
​
if(x1>x2){
l=mid+1;
}else{
r=mid-1;
}
​
}
return l;
}