class Solution {
public:
    bool isPowerOfThree(int n) {
         if(n<=0)
            return false;
        
        double i = (log10(n)/log10(3));
        
        return (i==(int)i);      
    }
};