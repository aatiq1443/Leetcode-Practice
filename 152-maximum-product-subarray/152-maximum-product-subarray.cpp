class Solution {
public:
    int maxProduct(vector<int>& nums) {     
        int m=nums.size();
        int ans=INT_MIN;
        int sum=1;
        for(int i=0;i<m;i++){
            sum=sum*nums[i];
            if(ans<sum) ans=sum;
           if(sum==0)  sum=1;
        }
       int n=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            n*=nums[i];
            if(ans<n)  ans=n;
            if(n==0) n=1;
        }
        return ans;   

        
    }
};