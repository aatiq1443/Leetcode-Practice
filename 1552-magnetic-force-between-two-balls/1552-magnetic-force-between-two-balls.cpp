class Solution {
public:
    
    bool isPossible(int n , int m , vector<int> &arr , int dis){
    
        int no_basket = 1;
        int pre_ele= arr[0];

        for(int i=1 ; i< n;i++){
            if(arr[i]-pre_ele >= dis){
                no_basket++;
                if(no_basket == m) return true;
                pre_ele = arr[i];
            }
        }

        return false;
    }
    
    int maxDistance(vector<int>& pos, int k) {
        sort(pos.begin() , pos.end());
    
        int n = pos.size();

        int st = 0;
        int end = pos[n-1] - pos[0];
        int ans = -1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(isPossible(n , k , pos , mid)){
                ans = mid;
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
       
        return ans;
    }
};