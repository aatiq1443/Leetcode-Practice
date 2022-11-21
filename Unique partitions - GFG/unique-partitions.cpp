//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>> fans;
	void dfs(int n , vector<int >& ans , int cur , int prev  ){
	    if(cur > n){
	        return ;
	    }
	    if(n == 0){
	        fans.push_back(ans);
	        return ;
	    }
	    dfs(n , ans , cur + 1 , prev);
	    if(cur != 0 and cur <= prev){
	        ans.push_back(cur);
	        dfs(n - cur , ans , 0 , cur);
	        ans.pop_back();
	    }
	    
	    
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int>ans;
        dfs(n , ans , 0 , n + 1);
      
        return fans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends