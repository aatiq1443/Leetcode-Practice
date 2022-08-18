class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        priority_queue<int> pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        
        int count=0;
        int value=0;
        while(!pq.empty()){
            value=value+pq.top();
            pq.pop();
            count++;
            if(value>=n/2){
                return count;
            }
        }
        return 0;
    }
};