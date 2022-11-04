//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int cnt = 0;
        int val = N;
        
        while(N!=0){
            int temp = N%10;
            if(temp != 0){
                if(val % temp == 0) cnt++;   
            }
            N = N/10;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends