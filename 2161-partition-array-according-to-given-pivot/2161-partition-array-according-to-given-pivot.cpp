class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
         vector<int>x;
         int n=nums.size();
        
            for(int i=0;i<n;i++){
                if(nums[i]<pivot)
                x.push_back(nums[i]);
              }
        
              for(int i=0;i<n;i++){
                if(nums[i]==pivot)
                    x.push_back(nums[i]);
              }
        
               for(int i=0;i<n;i++){
                if(nums[i]>pivot)
                    x.push_back(nums[i]);
              }
        
           return x;  
        
    }
};