class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         
        stack<pair<int,int>> s;  
        
        int mini = INT_MAX;   
        
        for(int i = 0;i<nums.size();i++){
            
            if(s.size()!=0)
            mini = min(mini,s.top().first);     
            
            while(s.size()!=0 && nums[i]>s.top().first){   
                s.pop();
            }
            
            if(s.size()!=0){        
                
            if((s.top().first > nums[i]) && (nums[i] > s.top().second))return true;
            }
            
            s.push({nums[i],mini});  
                  
        }
 
        return false;
    }
};