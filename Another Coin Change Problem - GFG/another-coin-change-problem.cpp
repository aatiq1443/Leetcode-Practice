//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
             vector <int> moves(target+1,0);
        for(int i=0;i<N;i++){
            if(coins[i]<=target){
                moves[coins[i]]=1;
            }
        }
        for(int i=1;i<K;i++){
            vector <int> freshmoves(target+1,0);
            for(int j=0;j<=target;j++){
                if(moves[j]==1){
                    for(int k=0;k<N;k++){
                        if((j+coins[k])<=target){
                            freshmoves[j+coins[k]]=1;
                        }
                    }
                }
            }
            moves=freshmoves;
        }
        return moves[target]==1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends