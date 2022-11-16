class Solution {
public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         map<string , int>mp;
        
//         vector<string> vec;
//         for(auto i:words){
//             mp[i]++;
//         }
        
//         for(auto i=0 ;i<words.size() ; i++){
//             if(mp[words[i]] == k){
//                 vec.push_back(words[i]);
//                 mp[words[i]]=0;
//             }
//         }
        
//         return vec;
    
    
struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            else{
                return a.first > b.first;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
                
        unordered_map<string, int> mp;
        
        for(auto word : words){
            mp[word]++;
        }
        
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        
        for(auto x : mp){
            if(pq.size() < k){
                pq.push({x.second, x.first});
            }
            else{
                if(pq.top().first < x.second || (pq.top().first == x.second && pq.top().second > x.first)){
                    pq.pop();
                    
                    pq.push({x.second, x.first});
                }
            }
        }
        
        
        vector<string> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            
            pq.pop();
        }
        
        
        reverse(res.begin(), res.end());
        
        return res;
    
    
    }
};