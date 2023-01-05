class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin() , points.end());
        
        int count = 0, i = 0;
        int n = points.size();
        
        while (i < n) {
            
            int maxVal = points[i][1];
            while (i < n && points[i][0] <= maxVal) 
                maxVal = min(maxVal, points[i++][1]);
            count++;
            
        }
        
        return count;
        
    }
};