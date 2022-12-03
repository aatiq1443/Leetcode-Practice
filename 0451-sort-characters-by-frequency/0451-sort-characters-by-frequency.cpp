class Solution {
public:
    string frequencySort(string s) {
//         unordered_map<char , int> mp;
//         priority_queue<pair<char , int>> pq;
        
//         for(auto i:s){
//             mp[i]++;
//         }
        
//         for(auto i:mp){
//             pq.push({i.second , i.first});
//         }
//        string ans="";
//         while(!pq.empty()){
//             for(int i=0;i<(pq.top().first);i++){
//                 ans.push_back(pq.top().second);
//             }
//             pq.pop();
//         }
//         return ans;
        
        unordered_map<char, int> freq;
        for (auto a : s) freq[a]++;
        
        priority_queue<pair<int, char>> q;
        for (auto [a, frq] : freq) q.push({frq, a});
        
        string res;
        pair<int, char> curr;
        while (!q.empty()) {
            curr = q.top();
            q.pop();
            res += string(curr.first, curr.second);
        }
        
        return res;
    }
};