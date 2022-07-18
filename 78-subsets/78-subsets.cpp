class Solution {
private:
    void solve(vector<vector<int>> & ans , vector<int> & ds , vector<int>&arr, int n , int i){
        
        if(i==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[i]);
        solve(ans,ds,arr , n, i+1);
        ds.pop_back();
        solve(ans,ds,arr,n , i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,nums,n,0);
        return ans;
    }
};