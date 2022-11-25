class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int p1=0;
        int p2=0;
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        // sort(nums1.size());
        sort(nums2.begin(),nums2.end());
        while(p1<n and p2<m){
            if(nums1[p1]>nums2[p2]){
                p2++;
            }
            else if(nums1[p1]<nums2[p2]){
                p1++;
            }
            else{
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ans;
        
    }
};