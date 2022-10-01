class Solution {
public:
    int numTrees(int n) {
       
        long long int size=2*n;
       
        long long int ans=1;
        
        for(int i=0;i<n;i++)
        {
            ans*=(size-i);
            ans/=(i+1);
        }
        return ans/(n+1);
    }
};