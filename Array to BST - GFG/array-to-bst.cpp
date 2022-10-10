//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    void solve(vector<int> &nums , int &i , vector<int>&ans , int st , int end){
        
        if(st > end) return ;
        
        
        int mid = st + (end-st) /2;
        
        ans.push_back(nums[mid]);
        
        solve(nums , i , ans , st ,mid-1);
        solve(nums , i , ans , mid+1 , end);
        
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        int i = 0;
        
        vector<int> ans;
        
        solve(nums , i , ans , 0 , nums.size()-1);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends