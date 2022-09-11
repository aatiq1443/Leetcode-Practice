class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        
        priority_queue<int> pq;
        
        int val=nums[0][0],temp;
       
        for(int i=0;i<nums.size() ;i++){
            
            if(!pq.empty() && nums[i][0] <= pq.top()) {
               temp=pq.top();
            }
            
            else if(!pq.empty()){
                
                 temp=pq.top();
                
                vector<int>ds;
                ds.push_back(val);
                ds.push_back(temp);
                ans.push_back(ds);
                
                
                val=nums[i][0];

            }
            
            
            
            pq.push(nums[i][1]);
           
             if(i==n-1){
                   
                 vector<int> v;
                    v.push_back(val);
                    v.push_back(pq.top());

                    ans.push_back(v);
                }
            
        }
        
        
        return ans;
    }
};