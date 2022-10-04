class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int currsum=0;
        int minsum = 0;
        int maxsum = 0;
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            
            if(currsum > maxsum){
                maxsum = currsum;
            }
            if(currsum < minsum){
                minsum = currsum;
            }
            
            int temp1 = currsum - minsum;
            int temp2 = maxsum - currsum;
            int res = max(temp1,temp2);
            
            if(res > ans){
                ans = res;
            }
        }
        
        return ans;
        
    }
};
