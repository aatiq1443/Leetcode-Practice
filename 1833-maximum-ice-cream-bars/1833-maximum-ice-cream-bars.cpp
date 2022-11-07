class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin() , costs.end());
        
        if(costs[0] > coins) return 0;
        
        int sum = 0;
        int cnt = 0;
        
        for(int i=0 ; i<costs.size() ; i++){

           
            
            if(sum+costs[i] <= coins){
                 sum = sum + costs[i];
                cnt++;
            }
            else break;
        }
        
        
        return cnt;
    }
};