class Solution {
public:
    int firstocc(vector<int>& arr,int m,int search)
{
    int mid,l,u;
    l=0;
    u=m-1;
    int ans=-1;
    
    while(l<=u)
    {
       mid=l+(u-l)/2;
        if(arr[mid]==search)
        {
            ans=mid;
            u=mid-1;
        }
       else if(arr[mid]<search)
        {
            l=mid+1;
        }
        else if(arr[mid]>search)
        {
            u=mid-1;
        }
    	 
    }
    return ans;

}
int secondocc(vector<int>& arr,int m,int search)
{
    int mid,l,u;
    l=0;
    u=m-1;
    int ans=-1;
    mid=l+(u-l)/2;
   while(l<=u)
   {
        if(arr[mid]==search)
        {
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]<search)
        {
            l=mid+1;

        }
        else if(arr[mid]>search)
        {
            u=mid-1;
        }
     mid=l+(u-l)/2;
    }
    return ans;

}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int temp1=firstocc(nums,n,target);
        int temp2=secondocc(nums,n,target);
        vector<int> ans;
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};