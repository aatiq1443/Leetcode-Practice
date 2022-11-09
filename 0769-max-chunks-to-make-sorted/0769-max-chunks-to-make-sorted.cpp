class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
      int count = 0;
      int maxi = 0;
        
      for(int i=0;i<arr.size();i++){
          
        maxi = max(maxi , arr[i]);
        if(maxi == i)
          count++;
      }
        
     return count;
        
    }
};