class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int temp=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int data=temp/2;
        cout<<data<<" "<<temp;
        if(temp%2==0){
            
            int dp[n+1][data+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<data+1;j++){
                    if(i==0){
                        dp[i][j]=false;
                    }
                    if(j==0){
                        dp[i][j]=true;
                    }
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<data+1;j++){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    }
                    else if(nums[i-1]>j){
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
               
            return dp[n][data];     
        }
        else{
            return false;
        }
    }
};