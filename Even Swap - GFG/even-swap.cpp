//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
                        int count=0;
            int c=2;
            for(int i=0;i<n-1;)
            {
                if((a[i]+a[i+1])%2==0)
                {
                    if(a[i]<a[i+1])
                    {
                        swap(a[i],a[i+1]);
                        if(i!=0)
                        {
                            i--;
                        }
                    }
                    else
                    {
                        i++;
                    }
                }
                else
                    i++;
            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends