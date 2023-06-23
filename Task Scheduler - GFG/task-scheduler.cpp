//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        
 int CHAR[26] = {0};
        
        //
        int maxF = -1;
        for(int i=0; i<N; i++) {
            
            CHAR[tasks[i]-'A'] += 1;
            maxF = max(maxF, CHAR[tasks[i]-'A']);
        }
        
        //
        int extraTime = 0;
        
        for(int i=0; i<26; i++){
            
            if(CHAR[i] == maxF) extraTime += 1;
        }
        
        //
        int totalTime = K * (maxF-1) + extraTime-1 + maxF;
        
        // cout<< K * (maxF-1) <<endl;
        // cout<< extraTime <<endl;
        // cout<< maxF <<endl;
        
        //
        return max(N, totalTime); // at least answer is N
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends