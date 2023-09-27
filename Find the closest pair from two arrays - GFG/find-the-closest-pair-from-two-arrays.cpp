//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
          int i = 0,j = m-1;
        int a1, b1, clsum  = INT_MAX;
        while(i<n && j>=0){
            if(abs(x-arr[i]-brr[j])<abs(x-clsum)){
                a1 = arr[i], b1 = brr[j];
                clsum = a1+b1;
            }
            if( arr[i]+brr[j]>x)j--;
            else if( arr[i]+brr[j]<x)i++;
            else{return {arr[i], brr[j]};}
        }
        return {a1, b1};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends