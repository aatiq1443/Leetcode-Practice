class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
        int curr1 = cost[0]; 
        int curr2 = cost[1];
        for(int i=2; i<n; i++){
            int temp = min(curr1, curr2) + cost[i];
            curr1 = curr2; 
            curr2 = temp; 
        }
        return min(curr1, curr2); 
    }
};