class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        stack<int> st;
        
        st.push(INT_MIN);
        
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            
            int curr=nums[i];
            while(st.top()!=INT_MIN and st.top()<=curr){
                
                st.pop();
            }
            
            nums[i] = st.top() == INT_MIN ? -1 : st.top();
            
            st.push(curr);
        }
        
        return nums;
        
    }
};