class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> ans(n , -1);
        
        if(2 * k + 1 > n) return ans;
        
        long long int sum = 0;

        for(int i =0 ; i < 2 * k + 1 ; i++) {
            sum += nums[i];
        }
        
        ans[k] = sum / (2 * k + 1);
        
        
        for(int i = 2 * k + 1 , j = k + 1, s = 0; i < n ; i++ , j++, s++) {
            
            sum += nums[i];
            sum -= nums[s];
            ans[j] = sum /(2 * k + 1);
            
        }
        
        return ans;
    }
};