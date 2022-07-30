class Solution {
public:
    int minSetSize(vector<int>& arr) {
         int n=arr.size();
        priority_queue<pair<int,int>> pq;
        map<int,int> mpp;
        for(auto i:arr){
            mpp[i]++;
        }
        for(auto i:mpp){
            pq.push({i.second,i.first});
        }
        int count=0;
        int temp=0;
        while(!pq.empty()){
          auto i=pq.top();
            temp+=i.first;
            count++;
            if(temp>=n/2){
                return count++;
            }
            pq.pop();
        }
        return mpp.size();
    }
};