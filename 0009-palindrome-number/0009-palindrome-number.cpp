class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int val = abs(x);
        
        if(temp !=val) return false;
        
        int data = x;
        
        long long res=0;
        
        while(data!=0){
            int var = data%10;
            res = res *10 + var;
            data = data/10;
        }
        
        if(res != x) return false;
        
        return true;
        
    }
};