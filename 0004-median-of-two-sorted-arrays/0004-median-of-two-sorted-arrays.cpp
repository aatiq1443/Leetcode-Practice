class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int i=0,j=0;
        vector<int>v;
        while(i<nums1.size() || j<nums2.size()){
            bool ans=j==nums2.size() || (i!=nums1.size() && nums1[i]<nums2[j]);
            v.push_back(ans?nums1[i++]:nums2[j++]);
        }
        if(v.size()%2==1)return float(v[v.size()/2]);
        else{
            float a,b;
            a=v[v.size()/2];
            b=v[(v.size()/2)-1];
            return (a+b)/2;
        }
        
    }
};