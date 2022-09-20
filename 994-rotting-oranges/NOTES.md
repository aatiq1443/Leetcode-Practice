class Solution {
public:
void dfs(int i ,int j , int target , vector<vector<int>> &grid){
if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()
|| grid[i][j]==0 ||grid[i][i]!=1 || grid[i][j]==2) return;
cout<<"j";
grid[i][j]=2;
// cnt++;
dfs(i-1 , j ,  target , grid);
dfs(i+1 , j ,  target , grid);
dfs(i , j-1 ,  target , grid);
dfs(i , j+1 ,  target , grid);
}
int orangesRotting(vector<vector<int>>& grid) {
int n= grid.size();
int m = grid[0].size();
int cnt=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++)
{
if(grid[i][j]==2){
cnt++;
dfs(i , j , grid[i][j]  , grid);
}
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
cout<<grid[i][j]<<" ";
}
cout<<endl;
}
return cnt;
}
};