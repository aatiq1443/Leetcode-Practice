#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0 , c=0;
        for(int i =0;i<=nums.size();i++){
            if(i<nums.size() && nums[i]==0 ) c++;
            else if(c != 0){
                ans +=(c*(c+1)/2);
                c=0;
            }
        } 
        return ans;
    }
};