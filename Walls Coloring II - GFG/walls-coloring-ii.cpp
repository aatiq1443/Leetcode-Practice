//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int minCost(vector<vector<int>> &c) {
        // write your code here
        int n = c.size();

    int k = c[0].size();

    if(n == 0 || k == 0) return 0;

    if(n != 1 && k == 1){

        return -1;

    }

    if(n == 1){

        int mn = INT_MAX;

        for(int i = 0; i < k; i++){

            mn = min(mn, c[0][i]);

        }

        return mn;
    }
    
    
       vector<vector<int>> dp(n, vector<int> (k, 0));

    

    

    int least = INT_MAX;

    int sleast = INT_MAX;

    

    for(int i = 0; i < k; i++){

        dp[0][i] = c[0][i];

        if(c[0][i] <= least){

            sleast = least;

            least = c[0][i];

        }

        else if(c[0][i] <= sleast){

            sleast = c[0][i];

        }

    }

    

    for(int i = 1; i < n; i++){

        int nleast = INT_MAX;

        int nsleast = INT_MAX;

        for(int j = 0; j < k; j++){

            

            if(least == dp[i-1][j]){

                dp[i][j] = sleast + c[i][j];

            }

            else{

                dp[i][j] = least + c[i][j];

            }

            

            if(dp[i][j] <= nleast){

                nsleast = nleast;

                nleast = dp[i][j];

            }

            else if(dp[i][j] <= nsleast){

                nsleast = dp[i][j];

            }

        }

        least = nleast;

        sleast = nsleast;

    }

    

    int ans = INT_MAX;

    for(int i = 0; i < k; i++){

        ans = min(ans, dp[n-1][i]);

    }

    

    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends