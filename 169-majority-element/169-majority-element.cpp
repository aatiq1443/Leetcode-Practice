class Solution {
public:
    int findCand(vector < int> &arr  , int n){
        int maj_ele=0;
        int count=1;
        
        for(int i=1;i<n;i++){
            if(arr[maj_ele]==arr[i]){
                count++;
            }
            else
                count--;
            if(count==0){
                maj_ele=i;
                count=1;
            }
        }
        
        return arr[maj_ele];
    }
    
    bool isMajority(vector<int> & arr , int n  , int cand){
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==cand){
                count++;
            }
        }
        if(count>n/2){
            return 1;
        }
        else
            return 0;;
    }
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int cand =findCand(nums,n);
        if(isMajority(nums,n,cand)){
            return cand;
        }
        return -1;
    }
};