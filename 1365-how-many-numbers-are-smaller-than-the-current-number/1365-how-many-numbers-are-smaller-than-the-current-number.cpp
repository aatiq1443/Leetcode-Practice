class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& vec) {
        
        vector<int> nums = vec;
        sort(nums.begin() , nums.end());
        
        map<int , int> mp;
        int n = nums.size();
        
        for(int i = n-1 ; i>=0 ; i--){
            mp[nums[i]] = i;
        }
        
        for(int i = 0 ; i< n ;i++){
            vec[i] = mp[vec[i]];
        }
        
        return vec;
        
    }
};