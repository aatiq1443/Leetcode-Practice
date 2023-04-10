//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int, int> map;  //create a map
        
       // range query for each range.
        for(auto i: lines) {
            int u = i[0], v = i[1] + 1;
            map[u]++, map[v]--;
        }
        
        int ans = 0, sum = 0;
        
        //prefix sum and maximum value
        for(auto i: map) {
            sum += i.second;
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends