//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
            int lo=0;
        int hi=s.size()-1;
        char c='a';

        while(lo<= hi)
        {
            if(s[lo]!='?')
           { c=s[lo];
            break;}
            else if(s[hi]!='?')
           { c=s[hi];
            break;}
            lo++;
            hi--;
        }
        lo=0;
        hi=s.size()-1;
        while(hi>=lo)
        {   
            if(s[lo]!=s[hi])
            {
                if(s[lo]!='?' && s[hi]=='?')
                s[hi]=s[lo];
                else if( s[hi]!='?' && s[lo]=='?')
                s[lo]=s[hi];
                else
                return -1;
                
                c=s[lo];
            }
            else if(s[hi]=='?' && s[lo]=='?')
            {
                s[hi]=c;
                s[lo]=c;
            }
            else
            {
                c=s[lo];
            }
          
          
            hi--;
            lo++;
        
            
        }
        int ans=0;
       
        for(int i=1;i<s.size();i++)
        {
            ans+=abs(s[i]-s[i-1]);
        }
        
    return ans;}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends