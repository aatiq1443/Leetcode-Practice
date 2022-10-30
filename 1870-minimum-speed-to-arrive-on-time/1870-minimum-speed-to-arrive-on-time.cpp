class Solution {
public:
    bool isvalid(vector<int>& a, int speed, double hour) {
        
        double time = 0;
        
        for (int i = 0; i < a.size(); i++) {
            
            time = ceil(time);
            time +=  (double)a[i] / speed;
            
            if (time > hour) return false;
        }
        return true;
    }

int minSpeedOnTime(vector<int>& dist, double hour) {
    
        int low = 1;
        int high = 1e9;

        int ans = -1;

        while(low <= high){

            int mid=low+(high-low)/2;

            if(isvalid(dist,mid,hour)){
                ans=mid;
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }

        return ans;
    }
};