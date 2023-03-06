class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        
         vector<double>sums(nums.size()+1, 0.0); 
        
        vector<vector<double>>dp(K+1, vector<double>(nums.size()+1, 0.0));
        
        for(int i =1 ; i <=nums.size(); i++){
            
            sums[i]= sums[i-1]+nums[i-1];
            dp[1][i]= static_cast<double>(sums[i])/i;
            
        }
        
        for ( int k = 2 ; k <= K ; k++){
            
            for ( int i = k ; i <=nums.size() ; ++i){
                
                for ( int j = k-1 ; j<i; ++j){
                    
                    dp[k][i]= max (dp[k][i], dp[k-1][j] + (sums[i]-sums[j]) /(i-j));
                    
                }
            }
        }
        
        return dp[K][nums.size()]; 
        
    }
};