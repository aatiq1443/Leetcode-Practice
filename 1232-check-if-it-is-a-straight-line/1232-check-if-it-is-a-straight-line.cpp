class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
           if(coordinates.size() == 2) return true;
		
        vector<int> point1 = coordinates[0];
        vector<int> point2 = coordinates[1];
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];
		
        for(int i = 2; i < coordinates.size(); i++){
            vector<int> point3 = coordinates[i];
            int x3 = point3[0];
            int y3 = point3[1];
            double area = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;
            if(area != 0) return false;
        }
        return true;
    }
};