//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int totalWays(int n, vector<int>cap) {
        // code here
        sort(cap.begin(), cap.end());
        int k = 0;
        int mod = 1000000007;
        long long ans = 1;
        for(auto it : cap)
        {
            it -= k;
            k++;
            ans *= it;
            ans %= mod;
        }
        return ans % mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends