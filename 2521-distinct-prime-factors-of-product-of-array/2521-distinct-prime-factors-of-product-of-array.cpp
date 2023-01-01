class Solution {
public:
    
    void primeFactors(long long int n,vector<int>&factor){
        int c=2;
        
        while(n>1){
            
            if(n%c==0){
            factor.push_back(c);
            n/=c;
            }
            
            else c++;
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        
        long long int res=1;
        int count=0;
        
        vector<int>factor
            ;
        for(int i=0;i<nums.size();i++){
            primeFactors(nums[i],factor);
        }
        
        
        map<int,int>mapping;
        
        for(auto i : factor)
            mapping[i]++;
        
        return mapping.size();
        
    }
};