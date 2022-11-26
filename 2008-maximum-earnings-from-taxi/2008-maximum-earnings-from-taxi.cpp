class Solution {
public:
     int getindex(vector<vector<int>>& jobs, int idx, const int& n)
{
	int lo = idx+1, hi = n-1, ans = n;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(jobs[idx][1] <= jobs[mid][0])
		{
			ans = mid;
			hi = mid-1;
		}
		else lo = mid + 1;
	}
	return ans;
}  
    
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        
        sort ( rides.begin() , rides.end() ) ;
        
        int siz = rides.size() ;
        
        vector<long long >dp ( siz + 1 , 0 ) ;
        
        for ( int i = siz - 1 ; i >=0 ; i-- ){
            
            int j = getindex ( rides , i , siz  ) ;
            
            long long take = 0 , nottake = 0 ;
            
            long long  x = rides [ i ] [ 2 ] + ( rides [ i ] [ 1 ] - rides [ i ] [ 0 ] ) ;
            
            take = x + dp [ j ] ;
            
            nottake = dp [ i + 1 ] ;
            
            dp [ i ] = max ( take , nottake ) ;          
        }
        
        return dp [ 0 ] ;
    }
};