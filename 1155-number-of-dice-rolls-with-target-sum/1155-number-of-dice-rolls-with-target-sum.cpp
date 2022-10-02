class Solution {
public:
	// int solve(int i,int tar,int k,int n){
	// 	if(i==n){
	// 		if(!tar) return 1;
	// 		return 0;
	// 	}    
	// 	int ans=0;
	// 	for(int j=1;j<=k;j++){
	// 		if(tar>=j) ans+=solve(i+1,tar-j,k,n);
	// 	}
	// 	return ans;
	// }
     int MOD = 1e9+7;
    
    int tabulation(int n, int k, int target){
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for(int j = 1; j<=k && j<target+1; j++)   dp[1][j] = 1;  
        
        for(int i = 2; i<n+1; i++){
            for(int j = 0; j<target+1; j++){
                for(int temp = 1; temp<=k; temp++){
                    if(j-temp>0) dp[i][j] += dp[i-1][j-temp];
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[n][target];        
    }
   
    
    int numRollsToTarget(int n, int k, int target) {
        // return solve(i , tar , k , n);
        return tabulation(n, k, target);
    }
};