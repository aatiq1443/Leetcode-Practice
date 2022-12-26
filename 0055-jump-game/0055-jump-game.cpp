class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int goal=n-1, i;
        
        for (i=n; i--;)
            if (i+nums[i] >= goal)
                goal=i;
        
        return !goal;
    }
};