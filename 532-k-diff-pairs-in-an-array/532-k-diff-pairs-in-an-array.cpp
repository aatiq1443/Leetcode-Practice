class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
		int fast=1;
		int slow=0;
		int ans=0;
        
		while(slow<nums.size() && fast<nums.size()){
            
			if(nums[fast]-nums[slow]==k){
				ans++;
				fast++;
				slow++;
				while(fast<nums.size() && nums[fast]==nums[fast-1]){
					fast++;
				}
			}
			else if(nums[fast]-nums[slow]>k){
				slow++;  
				if(fast-slow==0){
					fast++;}
			}
			else{      
				fast++;
			}         
		}
        
		return ans;
    }
};