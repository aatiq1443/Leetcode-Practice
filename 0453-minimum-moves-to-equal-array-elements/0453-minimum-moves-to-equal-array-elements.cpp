class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end()); 
        
        int minimum_element = nums[0];
        int answer = 0;
        
        for(int i=n-1; i>=0; i--){
            answer += (nums[i] - minimum_element);
        }
        
        return answer;
        
    }
};