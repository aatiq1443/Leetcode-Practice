class Solution {
    private:
    void solve(vector<vector<int>>&ans , vector<int>&ds , vector<int>& arr ,int temp , int i ,int n){
        if(i==n){
            if(temp==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[i]<=temp){
            ds.push_back(arr[i]);
            solve(ans,ds,arr,temp-arr[i],i,n);
            ds.pop_back();
        }
        solve(ans,ds,arr,temp,i+1,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n=c.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,c,target,0,n);
        return ans;
    }
};