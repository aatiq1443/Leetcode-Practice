class Solution {
private:
void solve(vector<vector<int>> &ans , vector<int> &ds , int n , int k ,int i){
if(ds.size()==k){
ans.push_back(ds);
return;
}
if(i==n+1){
return ;
}
ds.push_back(i);
solve(ans,ds,n,k,i+1);
ds.pop_back();
solve(ans,ds,n,k,i+1);
}
public:
vector<vector<int>> combine(int n, int k) {
vector<vector<int>> ans;
vector<int> ds;
solve(ans,ds,n,k,1);
return ans;
}
};