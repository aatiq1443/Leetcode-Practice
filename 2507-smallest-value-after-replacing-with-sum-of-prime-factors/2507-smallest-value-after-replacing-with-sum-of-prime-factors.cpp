class Solution {
public:
     bool isPrime(int n){
        if(n<2) return false;
        for(int i=2 ; i<=sqrt(n) ; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int smallestValue(int n) {
        if(isPrime(n)) return n;
        int mini = INT_MAX;
        int m = n;
        int sum;
        do
        { 
            sum = 0;
            while(n%2==0){
                sum += 2;
                n=n/2;
            }
            for(int i=3 ; i<=sqrt(n) ; i=i+2){
                while(n%i == 0){
                    sum += i;
                    n = n/i;
                }
            }
            if(n>2){
                sum += n;
            }
            mini = min(mini , sum);
            n = sum;
        }while(isPrime(sum) == false && sum < m);
        
        return mini;
    }  
    
};