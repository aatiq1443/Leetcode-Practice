//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> edge)
  {
      // code here
       if(N==1 && edge[0]==-1)

        return 0;

      unordered_map<int,int> mp;

      for(int i=0;i<N;i++)

      {

         if(mp.find(edge[i])==mp.end())

            mp[edge[i]]=i;

        else

            mp[edge[i]]+=i;

      }

      int mx=INT_MIN;

      int pos=0;

      for(auto it:mp)

      {

         if(mx<it.second){

            mx=it.second;

            pos=it.first;

         }

         else if(mx==it.second)

         {

             pos=max(pos,it.first);

         }

      }

      return pos;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends