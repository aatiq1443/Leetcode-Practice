//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
          int i=0,j=n-1;
        while(i<j){
            if(arr[i]>=arr[j]){
                arr[i]=arr[i]%arr[j];
            }
            else
                arr[j]=arr[j]%arr[i];
            if(arr[j]==0) j--;
            if(arr[i]==0) i++;
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends