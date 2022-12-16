class Solution {
public:
    int maxJump(vector<int>& stones) {
        
        int cost = stones[1]-stones[0];

        for(int i=2; i<stones.size(); i++){
            
            cost = max(cost, stones[i]-stones[i-2]);
        }
        return cost;
    }
};