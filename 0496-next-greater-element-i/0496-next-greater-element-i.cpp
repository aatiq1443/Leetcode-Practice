class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int flag;
        vector<int>ans;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                flag=0;
               
                if(nums1[i]==nums2[j]){
                    for(int k=j+1;k<m;k++){
                        if(nums2[k]>nums2[j]){
                    ans.push_back(nums2[k]);
                    flag=1;
                    break;
                    }
                  }
                
                
            if(flag==0) ans.push_back(-1);
                }
            }
        }
        return ans;
            
    }
};