//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
int ans = 0 ;
	    for(int j = 1 ; j<nums.size() -1  ; j++){
	        int smaller = 0 ; 
	        for(int i = j-1 ; i>=0 ; i--){
	            if(nums[i]<nums[j]) smaller++ ;
	        }
	        int greater = 0 ; 
	        for(int k =  j+1 ; k<nums.size() ; k++){
	            if(nums[j]<nums[k]) greater++ ;
	        }
	        ans = ans + smaller*greater ;
	    }
	    return ans ;	}
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
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends