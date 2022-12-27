class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
         int n(size(rocks)), res(0);
        
        for (int i=0; i<n; i++) {
            capacity[i] -= rocks[i];
        }
        
        sort(begin(capacity), end(capacity));
        
        for (int i=0; i<n and additionalRocks; i++) {
            
            if (capacity[i] <= additionalRocks) {
                additionalRocks -= capacity[i];
                res++;
            }
        }
        
        return res;
    }
};