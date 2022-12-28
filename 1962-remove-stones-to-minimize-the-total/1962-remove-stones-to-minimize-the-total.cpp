class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq; 
        for(auto &it:piles) pq.push(it); 

        int n;
        while(k-- && !pq.empty()) {
            
            n = pq.top(); pq.pop(); 
            n = n-n/2; 
            pq.push(n); 
            
        }

        int sum=0;
        
        while(!pq.empty()){
            sum += pq.top(); pq.pop();
        }
        
        return sum;
        
    }
};