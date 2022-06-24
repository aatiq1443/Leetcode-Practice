class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int maxi=0;
        int val;
        for(auto i:mp){
            if(i.second>maxi){
                maxi=i.second;
                val=i.first;
            }
        }
        return val;
    }
};