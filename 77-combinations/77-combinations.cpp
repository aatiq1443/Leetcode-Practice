class Solution {
private:
    void solve(vector<int>&arr,vector<vector<int>> &ans , vector<int> &ds , int n , int k ,int ind){
        if(ds.size()==k){
                ans.push_back(ds);
            return;
            }
       if(ind==n){
           
           return ;
       }
      
          ds.push_back(arr[ind]);
          solve(arr,ans,ds,n,k,ind+1);
          ds.pop_back();
       
      solve(arr,ans,ds,n,k,ind+1);
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> ds;
        solve(arr,ans,ds,n,k,0);
        return ans;
    }
};