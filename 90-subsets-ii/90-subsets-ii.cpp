class Solution {
private:
    void solve(vector<vector<int>>&ans , vector<int>&ds, vector<int>&arr, int n , int ind){
       
            // if(ind==n){
            //     // ans.push_back(ds);
            //     return;
            // }
          ans.push_back(ds);
        
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
             ds.push_back(arr[i]);
            solve(ans,ds,arr,n,i+1);
            
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
     vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,nums,n,0);
        return ans;
    }
};