int row=grid.size();
int col=grid[0].size();
for(int j=0;j<col;j++){
vector<int>vec;
for(int i=0;i<row;i++){
vec.push_back(grid[i][j]);
}
ans.push_back(vec);
}
}
int equalPairs(vector<vector<int>>& grid) {
int row=grid.size();
int col=grid[0].size();
vector<vector<int>> ans;
solve(grid,ans);
int count=0;
int n=ans.size();
for(int i=0;i<row;i++){
for(int j=0;j<n;j++){
if(grid[i]==ans[j]){
count++;
}
}
}
return count;