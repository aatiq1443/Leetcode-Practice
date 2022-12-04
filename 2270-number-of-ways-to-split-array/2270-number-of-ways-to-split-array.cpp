class Solution {
public:
    
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        long long int temp =nums[0]; 
        
        long long int val = 0;
        for (int i = 1 ;i<n;i++){
            
            val += (long long)nums[i]; 
        }
       
        int count = 0;
        for (int i = 1;i<n;i++)
        {
            if (temp >= val)
                count++;
            
            temp = temp + (long long)nums[i];
            val = val - (long long)nums[i];
        }
        return count;
        
    }
};