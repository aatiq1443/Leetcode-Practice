//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int> &piles , int mid){
        int sum= 0;
        
        for(int i=0 ;i< piles.size() ;i++){
            
            if(piles[i]%mid!=0){
                sum = (sum + (piles[i]/mid)) + 1;
            }
            else
            {
                sum = sum + (piles[i]/mid);
            }
            
        }
        return sum;
    }
  
    int Solve(int N, vector<int>& piles, int H) {
        
        int st = 0;
        int end = 1000000000;
        
        int ans = -1;
        
        while(st <= end){
            int mid = st + (end- st)/2;
            
            int time = solve(piles , mid);
            
            if(time <=H){
                ans = mid;
                end = mid-1;
            }
            else st = mid+1;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends