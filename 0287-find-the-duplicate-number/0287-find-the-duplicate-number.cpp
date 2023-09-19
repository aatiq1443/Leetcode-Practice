class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int temp;
        for(auto i:mp){
            if(i.second>1){
                temp=i.first;
            }
        }
        
        return temp;
    }
};