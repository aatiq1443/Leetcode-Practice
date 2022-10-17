class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> freq;

        for(auto x : nums) freq[x]++; 
       

        for(auto x : nums){
            if(freq[x] == 1) 
                return x;  
        }
        
        return -1; 
    }
};