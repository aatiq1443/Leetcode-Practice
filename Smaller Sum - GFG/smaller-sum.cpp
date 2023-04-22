//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
         vector<long long> ans;
    map<int, int> mp;
    map<int, long long> lessThan;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    long long lessSum = 0;
    for (auto it:mp) {
        lessThan[it.first] = lessSum;
        lessSum += (it.first) * (it.second);
    }
    
    for(int i=0;i<n;i++) ans.push_back(lessThan[arr[i]]);
    return ans;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends