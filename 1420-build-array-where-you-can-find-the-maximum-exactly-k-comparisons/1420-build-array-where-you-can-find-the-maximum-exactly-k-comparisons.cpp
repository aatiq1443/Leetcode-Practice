class Solution {
    
 int mod=1e9+7;
    
    int N,M;
    
    vector<vector<vector<long long>>>dp;
    
    long long findArrays(int i, int mx,int k){
        
        if(i==N-1)return k==0?1:0;
        if(k<0)return 0;
        
        if(dp[i][mx][k]!=-1)return dp[i][mx][k];
        
        long long ans=0;
        
        for(int j=1;j<=M;j++){
            ans=(ans+findArrays(i+1,max(mx,j),j>mx?k-1:k))%mod;
        }
        
        return dp[i][mx][k]=ans;
        
    }
    
public:
    
    int numOfArrays(int n, int m, int k) {
        
        long long ans=0;
        N=n;
        M=m;
        
        dp.resize(n,vector<vector<long long>>(m+1, vector<long long>(k,-1)));
        
        for(int j=1;j<=m;j++){
            ans=(ans+findArrays(0,j,k-1))%mod;
        }
        
        return ans;
    }
};