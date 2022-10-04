class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
//         int temp = pow(10 , n);
//         // cout<<temp;
//         long long int cnt=0;
//         for(int i=10 ; i<temp ; i++){
//             int nums = i;
//             int size=0;
            
//             while(nums!=0){
//                 size++;
//                 cout<<nums<<" ";
//                 nums= nums/10;
//                 cout<<nums<<" "<<size<<"      ";
//             }
//             // cout<<size<<" ";
//             if(size==n && ) cnt++;
//         }
        
//         return n==1?cnt+1 :cnt ;
        
         if(n == 0)
            return 1;
        
        int ans = 10, calc = 9, temp = 9;
        
        for(int i = 0; i < n - 1; i++) {
            calc *= temp;
            ans += calc;
            temp--;
        }
        
        return ans;
      
        
    }
};