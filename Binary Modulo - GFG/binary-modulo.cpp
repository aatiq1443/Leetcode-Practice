//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
             long long int ans=0;
           long long int ex=1;
           int n=s.size();
           for(int i=n-1;i>=0;i--)
           {
               int x=s[i]-'0';
               
               ans=(ans+x*ex)%m;
               ex=(ex*2)%m;
           }
           return ans%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends