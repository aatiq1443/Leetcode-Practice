class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int prev = 0, curr = 0;
        int ans = 0;
        for (int i : nums) {
            if (i == 1)
                curr++;
            else {
                ans = std::max(ans, curr + prev);
                prev = curr;
                curr = 0;
            }
        }
        ans = std::max(ans, curr + prev);

        return (ans == nums.size()) ? ans - 1 : ans;
    }
};