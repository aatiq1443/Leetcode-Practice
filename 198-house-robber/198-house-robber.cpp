class Solution {
public:
    
//     int solve(vector<int> &ans, vector<int> &dp , int n){
        
//         if(n==0) return ans[n];
        
//         if(n<0) return 0;
        
//         if(dp[n]!=-1) return dp[n];
        
//         int left = ans[n] + solve(ans , dp , n-2);
        
//         int right =0 + solve(ans , dp , n-1);
        
//         return dp[n]=max(left , right);
        
//     }
    
//     int tabu(vector<int> &arr , vector<int> &dp , int n){
//         dp[0]=arr[0];
        
//         for(int i=1;i<n;i++){
//             int left = arr[i] ;
//             if(i>1) left+=dp[i-2];
//             int right = 0 + dp[i-1];
            
//             dp[i] = max(left, right);
//         }
//         return  dp[n-1];
        
//     }        
       
    int rob(vector<int>& arr) {
       
        int n= arr.size();
        int prev= arr[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int left = arr[i] ;
            if(i>1) left+=prev2;
            
            
            int right = 0 + prev;
            
            int curr= max(left  , right);
            
            prev2 = prev;
            prev = curr;
            
        
        }
        
        return prev;
        
        
        
        
        
        
        
        
        
        
        
        // int ans=solve(nums , dp , n);
        // int ans=tabu(nums , dp , n);
        // return ans;
        
    }
};