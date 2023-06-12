class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
          vector<string>ans;
        int i=0;
        while(i<nums.size())
        {
            int j=i;
            while(i+1<nums.size() && nums[i]==nums[i+1]-1)
            {
                i++;
            }
            if(i==j)
            {
                ans.push_back(to_string(nums[j]));
            }
            else
            {
                ans.push_back(to_string(nums[j])+"->"+to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};