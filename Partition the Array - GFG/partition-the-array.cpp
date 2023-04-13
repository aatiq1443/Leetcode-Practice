//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    #define ll long long
ll  binsearch(ll arr[],int l,int h, ll sum,ll temp){
    ll s=l,e=h,ans=INT_MAX,ind=-1;
    while(s<=e){
        ll mid=s+(e-s)/2;
        ll first=arr[mid]-temp;
        ll second=sum-arr[mid];
        if(abs(second-first)<ans){
            ans=abs(second-first);
            ind=mid;
        }
        if(first<second){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        
    }
    return ind;
}
    long long minDifference(int N, vector<int> &A) {
        // code here
        ll arr[N];
        arr[0]=A[0];
        for(int i=1;i<N;i++){
            arr[i]=A[i]+arr[i-1];
        }
        ll w,x,y,z;
        ll ans=INT_MAX;
        
        for(int i=2;i<N-1;i++){
         ll index=binsearch(arr,0,i-1,arr[i-1],0);
         w=arr[index];
         x=arr[i-1]-w;
         index=binsearch(arr,i,N-1,arr[N-1],arr[i-1]);
         y=arr[index]-arr[i-1];
         z=arr[N-1]-arr[index];
         ll k=max({w,x,y,z})-min({w,x,y,z});
         ans=min(ans,k);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends