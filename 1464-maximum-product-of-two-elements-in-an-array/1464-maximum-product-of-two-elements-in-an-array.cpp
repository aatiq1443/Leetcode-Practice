class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int ans;
        int total;
        while(!pq.empty()){
            int data1=pq.top();
            pq.pop();
            int data2=pq.top();
            pq.pop();
             total=(data1-1)*(data2-1);
            break;
        }
        return total;
        
    }
};