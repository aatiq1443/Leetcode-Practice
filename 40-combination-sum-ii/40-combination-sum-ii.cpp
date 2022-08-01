class Solution {
public:
    void solve(vector<int> arr ,  vector<vector<int>> &ans , vector<int> ds , int n , int target , int ind){
        if(target==0){
            ans.push_back(ds);
            return ;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            solve(arr,ans,ds,n,target-arr[i],i+1);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums,ans,ds,n,target,0);
        return ans;
    }
};