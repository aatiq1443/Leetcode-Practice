//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
                if(n==1)return false;
        map<string, int> mp;
        if(arr[0].size()==1||arr[0].size()==2){
            for(int i=0;i<n;i++){
                mp[arr[i]]++;
            }
            int count=0;
            for(auto it:mp){
                if(it.second%2!=0)
                count++;
                if(count>1)return false;
            }
        }
        mp.clear();
       if(n==2){
          string temp1=arr[0];
          string temp2=arr[1];
          reverse(temp1.begin(),temp1.end());
          reverse(temp2.begin(),temp2.end());
          if(temp1==arr[0]&&temp2==arr[1])
          return false;
       }
          
        
        for(auto itr : arr)
        {
            ++mp[itr];
            reverse(itr.begin(),itr.end());
            ++mp[itr];
        }
        
        for(auto itr : mp)
        {
            if(itr.second & 1)
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends