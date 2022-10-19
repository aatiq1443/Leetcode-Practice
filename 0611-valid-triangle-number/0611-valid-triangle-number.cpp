class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n<3) return 0;
        
        sort(nums.begin(),nums.end());
        int count=0;
        
        for(int i=2;i<n;i++){
            
            int st=0;
            int end=i-1;
            while(st<end){
                
                if(nums[st]+nums[end]>nums[i]){
                    count+=end-st;
                    end--;
                    }
                
                else
                    st++;
            }
        }
        return count;
        
    }
};