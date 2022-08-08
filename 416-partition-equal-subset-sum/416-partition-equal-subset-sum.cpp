class Solution {
public:
    bool canPartition(vector<int>& ans) {
        int n=ans.size();
       	int temp=accumulate(ans.begin(),ans.end (),0);
	int sum=temp/2;
	int dp[n+1][sum+1];
	if(temp%2==0){
		for(int i=0;i<n+1;i++){
			for(int j=0;j<sum+1;j   ++){
				if(i==0) dp[i][j]=false;
				if(j==0) dp[i][j]=true;
			}
		}

		for(int i=1;i<n+1;i++){
			for(int j=1;j<sum+1;j++){
				if(ans[i-1]<=j){
					dp[i][j]=dp[i-1][j-ans[i-1]] || dp[i-1][j];
				}
				else if(ans[i-1]>j){
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		return dp[n][sum];
	}
	else{
		return false;
	}
    }
};