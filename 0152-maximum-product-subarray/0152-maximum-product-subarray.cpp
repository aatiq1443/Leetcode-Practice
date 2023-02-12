class Solution {
public:
    int maxProduct(vector<int>& nums) {     
       
         int n = nums.size();

        int maxi =1 , mini=1, res = INT_MIN;

        for(int i =0;i<n;i++){
            int temp = maxi;
            
            maxi = max({nums[i] , maxi*nums[i] , mini*nums[i]});
            mini = min({nums[i] , temp*nums[i] , mini*nums[i]});
        

            res = max({maxi,mini,res});
        }
        return res;
    }
};