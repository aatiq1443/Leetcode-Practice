class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int , int> mp;
        priority_queue<pair<int , int>> pq;
        
        for(auto i:nums){
            mp[i]++;
        }
        
        for(auto i:mp){
            pq.push({-i.second , i.first});
        }
        vector<int>ans;
        while(!pq.empty()){
            for(int i=0;i<-(pq.top().first);i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
        
    }
};