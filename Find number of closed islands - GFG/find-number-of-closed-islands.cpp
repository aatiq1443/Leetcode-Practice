//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
       bool solve(vector<vector<int>>&mat,int i,int j,int n,int m){
        if(i>=n||i<0||j<0||j>=m)return false;
        if(mat[i][j]==0||mat[i][j]==2)return true;
        mat[i][j]=2;
        bool l=solve(mat,i-1,j,n,m);
        bool r=solve(mat,i+1,j,n,m);
        bool u=solve(mat,i,j-1,n,m);
        bool d=solve(mat,i,j+1,n,m);
        return l&&r&&u&&d;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
     int ans=0;
      for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              if(matrix[i][j]==1){
                  if(solve(matrix,i,j,N,M)){
                      ans++;
                      
                  }
              }
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends