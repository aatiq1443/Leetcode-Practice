class Solution {
public:
     //handling the edge case while sorting

     static bool compare(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        
          int n=nums.size();
          sort(nums.begin(), nums.end() ,compare); 
        
//           for(int i=0;i<nums.size();i++){
//               for(int j=0;j<nums[i].size();j++){
//                   cout<<nums[i][j]<<" ";
//               }
          
              
//               cout<<endl;
//           }
          int maxi = INT_MIN;                               
          int ans = 0;
          
          for(int i=n-1 ;i>=0 ;i--){
              if(nums[i][1] < maxi) ans++;
              
              maxi=max(maxi , nums[i][1]);
          }
        return ans;
    }
};
