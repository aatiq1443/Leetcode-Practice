class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int p=accumulate(nums.begin(),nums.end(),0);
        ans.push_back(p);
        int temp=p;
        for(int i=n-1;i>0;i--){
            temp=temp-nums[i];
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};