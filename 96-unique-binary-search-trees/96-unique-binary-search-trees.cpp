class Solution {
public:
    int numTrees(int n) {
        
        long long int a=2*n;
        int b=n;
		
        int i,j;
        long long int ans=1;
        for(i=0;i<b;i++)
        {
            ans*=(a-i);
            ans/=(i+1);
        }
        return ans/(b+1);
    }
};