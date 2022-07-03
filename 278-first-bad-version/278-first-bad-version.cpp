// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int s=0;
        int e=n-1;
        int result=n;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(isBadVersion(mid)){
                result=mid;
                e=mid-1;
                
            }
            else{
                s=mid+1;
            }
        }
        return result;
        
    }
};