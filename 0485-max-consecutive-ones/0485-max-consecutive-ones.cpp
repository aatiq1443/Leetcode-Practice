class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int x;
        int count=0;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==0)
           {
               count=0;
           }
            else
            {
                count++;
                result=max(result,count);
            }
        }
        return result;
        
    }
};