class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
           int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(grid[i][mid]<0){
                    r=mid-1;
                }else
                    l=mid+1;
            }
            if(l<n&&grid[i][l]<0){
                ans+=(n-l);
            }
                
        }
        return ans;
    }
};