class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(mp.count(diff)==1 and mp[diff]!=i){
                ans.push_back(i);
                ans.push_back(mp[diff]);
                break;
            }
        }
        return ans;
    }  
};