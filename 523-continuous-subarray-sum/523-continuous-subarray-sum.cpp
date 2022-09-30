class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n<=1) return 0;
        
        map<int, int> mp;
        
        int sum =0, rem =0;
        mp[0] = -1;
        for(int i =0; i<n;i++){
            sum += nums[i];
            rem = sum%k;
                      
            if(mp.count(rem)==0){
                mp[rem]= i;
            }
            
            else if(i-mp[rem] >1){
                return true;
            }
        }
        return false;
        
    }
};