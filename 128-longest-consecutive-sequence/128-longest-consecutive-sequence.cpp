class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int count=1,ans=0 , prev;
        for(auto i:mp){
           if(ans==0){
               prev=i.first;
               ans=1;
           }
            else{
                if(i.first==(prev+1)){
                    count++;
                    ans=max(ans,count);
                }
                else{
                    count=1;
                }
                prev=i.first;
            }
        }
        return ans;
    }
};