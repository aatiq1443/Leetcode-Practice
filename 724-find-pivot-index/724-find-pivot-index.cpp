class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
            ans.push_back(nums[i]);
        }
        int m=ans.size();       
        int prev;
        int next;
        int temp=0;
        int x;
        for(int i=0;i<m;i++){
            if(i==0){
                prev=0;
            }
            else{
            prev=ans[i-1];  
            }
            next=ans[m-1]-ans[i];
            if(prev==next){
//                 temp=1;
//                 x=i;
                
//                 break;
                return i;
            }
        }
        // if(temp==0){
        //     return -1;
        // }
        // else{
        //     return x;
        // }
        return -1 ;
    }
};