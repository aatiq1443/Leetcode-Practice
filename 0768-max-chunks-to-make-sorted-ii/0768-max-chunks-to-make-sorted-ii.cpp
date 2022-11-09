class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        long long sum1 = 0, sum2 = 0;
        int res = 0;
        
        vector<int> ans = arr;
        
        sort(ans.begin(), ans.end());
        
        for(int i = 0; i < arr.size(); i++) {
            
            sum1 += ans[i];
            sum2 += arr[i];
            
            if(sum1 == sum2)
                res++;
            
        }
        
	    return res;
        
    }
};