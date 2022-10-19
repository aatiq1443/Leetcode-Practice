//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
   bool isPossible(int arr[] , int n , int m , long long mid){
    
        int st_cnt = 1;
        int pages = 0;
        
        for(int i =0 ;i<n ;i++){
            if(pages + arr[i] <=mid){
                pages+=arr[i];
            }
            else{
                st_cnt++;
                if(st_cnt > m || arr[i] > mid) return false;
                pages = arr[i];
            }
        }    
        return true;
}
  
  
    long long minTime(int arr[], int n, int k)
    {
        long long st = 0;
        long long sum = 0;
        for(int i=0 ;i<n ; i++){
            sum += arr[i];
        }
        long long ans = -1;
        long long end = sum;
        while(st <= end){
            long long mid = st + (end-st)/2;
            if(isPossible(arr , n , k , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends