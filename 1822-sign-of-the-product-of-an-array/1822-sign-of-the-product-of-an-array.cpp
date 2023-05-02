class Solution {
public:
    int arraySign(vector<int>& v) {
        int count=0;
        int n=v.size();       
        for(int i=0;i<n;i++){
            if (v[i]==0) return 0;
            if(v[i]<0) count++;
        }
        if(count%2==0) return 1;
        else return -1;
    }
};
