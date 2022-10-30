class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int res = 0;
        
        sort(nums.begin(),nums.end()); 
        
        int st = 0;
        int end = nums.size() - 1;
        while(st<end){
            
            res += nums[end] - nums[st]; 
            st++;
            end--;
        }
        return res;
    }
};