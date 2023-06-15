//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
         int s = 0, e = 0, l = 0, h = 0;
        for(int i = 0; i<S.size(); i++)
        {
            l = i-1, h = i+1;
            while(l>=0 and S[i] == S[l])
                l--;
            while(h<S.size() and S[i] == S[h])
                h++;
            while(l>=0 and h < S.size() and S[l] == S[h])
                l--,h++;
            if(e < h-l-1)
                s = l+1,e = h-l-1;
        }
        return S.substr(s,e);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends